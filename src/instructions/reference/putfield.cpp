#include "putfield.hpp"
#include "../../rtda/heap/clase.hpp"
#include "../../rtda/heap/field_ref.hpp"
#include "../../rtda/heap/object.hpp"
#include <iostream>

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void PUT_FIELD::Execute(Frame* frame){
	Method* current_method = frame->getMethod();
	Clase* current_clase = current_method->getClase();
	ConstantPool* cp = current_clase->constant_pool_;
	FieldRef* field_ref = getConstant<FieldRef*>(cp->getConstants(), getIndex());
	Field* field = field_ref->ResolvedField();
	
	if (!field->IsStatic()){
		std::cout << "java.lang.IncompatibleClassChangeError" << std::endl;
		return;
	}

	if (field->IsFinal()){
		if ((current_clase != field->getClase()) || current_method->getName() != std::string("<init>")){
			std::cout << "java.lang.IllegalAccessError" << std::endl;
			return;
		}
	}

	std::string descriptor = field->getDescriptor();
	uint16	slotId = field->getSlotId();
	OperandStack* stack = frame->GetOperandStack();

	Object* ref = NULL;
	switch (descriptor.at(0)) {
	case 'Z':
	case 'B':
	case 'C':
	case 'S':
	case 'I':{
				 int32   val1 = stack->PopInt();
				 ref = stack->PopRef();
				 if (NULL == ref){
					 std::cout << "java.lang.NullPointerException" << std::endl;
					 return;
				 }
				 ref->getFields()->SetInt(slotId, val1);
				 break; }
	case 'F':{
				 float32   val2 = stack->PopFloat();
				 ref = stack->PopRef();
				 if (NULL == ref){
					 std::cout << "java.lang.NullPointerException" << std::endl;
					 return;
				 }
				 ref->getFields()->SetFloat(slotId, val2);
				 break; }
	case 'J':{
				 int64   val3 = stack->PopLong();
				 ref = stack->PopRef();
				 if (NULL == ref){
					 std::cout << "java.lang.NullPointerException" << std::endl;
					 return;
				 }
				 ref->getFields()->SetLong(slotId, val3);
				 break; }
	case 'D':{
				 float64   val4 = stack->PopDouble();
				 ref = stack->PopRef();
				 if (NULL == ref){
					 std::cout << "java.lang.NullPointerException" << std::endl;
					 return;
				 }
				 ref->getFields()->SetDouble(slotId, val4);
				 break; }
	case 'L':
	case '[':{
				 Object*   val5 = stack->PopRef();
				 ref = stack->PopRef();
				 if (NULL == ref){
					 std::cout << "java.lang.NullPointerException" << std::endl;
					 return;
				 }
				 ref->getFields()->SetRef(slotId, val5);
				 break; }
	default:
		// todo
		std::cout << "to to" << std::endl;
	}
}