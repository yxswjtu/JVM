#include "getfield.hpp"
#include "../../rtda/heap/field_ref.hpp"
#include "../../rtda/heap/object.hpp"

#include <iostream>

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void GET_FIELD::Execute(Frame* frame){
	ConstantPool* cp = frame->getMethod()->getClase()->constant_pool_;
	FieldRef* field_ref =getConstant<FieldRef*>(cp->getConstants(),getIndex());
	Field* field = field_ref->ResolvedField();

	if (!field->IsStatic()){
		std::cout << "java.lang.IncompatibleClassChangeError" << std::endl;
		return;
	}	

	OperandStack* stack = frame->GetOperandStack();
	Object* ref = stack->PopRef();
	if (NULL == ref){
		std::cout << "java.lang.NullPointerException" << std::endl;
		return;
	}

	std::string descriptor = field->getDescriptor();
	uint16	slotId = field->getSlotId();
	Slot* slots = ref->getFields();
	

	switch (descriptor.at(0)) {
	case 'Z':
	case 'B':
	case 'C':
	case 'S':
	case 'I':
		stack->Push(slots->GetInt(slotId));
		break;
	case 'F':
		stack->Push(slots->GetFloat(slotId));
		break;
	case 'J':
		stack->Push(slots->GetLong(slotId));
		break;
	case 'D':
		stack->Push(slots->GetDouble(slotId));
		break;
	case 'L':
	case '[':
		stack->Push(slots->GetRef(slotId));
		break;
	default:
		// todo
		std::cout << "tod " << std::endl;
	}
}