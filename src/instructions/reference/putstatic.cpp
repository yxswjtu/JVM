#include "putstatic.hpp"
#include "../../rtda/heap/method.hpp"
#include "../../rtda/heap/clase.hpp"
#include "../../rtda/heap/field_ref.hpp"
#include "../../rtda/stack/slot.hpp"

#include <iostream>

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void PUT_STATIC::Execute(Frame* frame){
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

	if (field->IsFinal()){
		if ((current_clase != clase) || current_method->getName() != std::string("<clinit>")){
			std::cout << "java.lang.IllegalAccessError" << std::endl;
			return;
		}
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
			slots->SetInt(slotId, stack->PopInt());
			break;
		case 'F':
			slots->SetFloat(slotId, stack->PopFloat());
			break;
		case 'J':
			slots->SetLong(slotId, stack->PopLong());
			break;
		case 'D':
			slots->SetDouble(slotId, stack->PopDouble());
			break;
		case 'L':
		case '[':
			slots->SetRef(slotId, stack->PopRef());
			break;
		default:
			// todo
			std::cout << "to do " << std::endl;
	}
}