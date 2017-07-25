#include "getstatic.hpp"
#include "../../rtda/heap/clase.hpp"
#include "../../rtda/heap/field_ref.hpp"

#include <iostream>

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void GET_STATIC::Execute(Frame* frame){
	Method* current_method = frame->getMethod();
	Clase* current_clase = current_method->getClase();
	ConstantPool* cp = current_clase->constant_pool_;
	FieldRef* field_ref = getConstant<FieldRef*>(cp->getConstants(),getIndex());
	Field* field = field_ref->ResolvedField();
	Clase* clase = field->getClase();
	//
	if (!field->IsStatic()){
		std::cout << "java.lang.IncompatibleClassChangeError" << std::endl;
		return;
	}

	std::string descriptor = field->getDescriptor();
	uint16	slotId = field->getSlotId();
	Slot* slots = clase->getStaticVars();
	OperandStack* stack = frame->GetOperandStack();

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