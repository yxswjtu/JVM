#include "checkcast.hpp"
#include "../../rtda/heap/object.hpp"
#include "../../rtda/heap/clase.hpp"
#include "../../rtda/heap/clase_ref.hpp"

#include <iostream>

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void CHECK_CAST::Execute(Frame* frame){
	OperandStack* stack = frame->GetOperandStack();
	Object* ref = stack->PopRef();
	stack->Push(ref);

	if (NULL == ref){		
		return;
	}

	ConstantPool* cp = frame->getMethod()->getClase()->constant_pool_;
	ClaseRef* classref = getConstant<ClaseRef*>(cp->getConstants(),getIndex());
	Clase* clase = classref->ResolvedClass();

	if (!ref->IsInstanceOf(clase)){
		std::cout << "java.lang.ClassCastException" << std::endl;
	}

}