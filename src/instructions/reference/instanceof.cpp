#include "instanceof.hpp"
#include "../../rtda/heap/object.hpp"
#include "../../rtda/heap/clase.hpp"
#include "../../rtda/heap/clase_ref.hpp"

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void INSTANCE_OF::Execute(Frame* frame){
	OperandStack* stack = frame->GetOperandStack();
	Object* ref = stack->PopRef();

	if (NULL == ref){
		stack->Push(0);
		return;
	}

	ConstantPool* cp = frame->getMethod()->getClase()->constant_pool_;
	ClaseRef* classref = getConstant<ClaseRef*>(cp->getConstants(),getIndex());
	Clase* clase = classref->ResolvedClass();

	if (ref->IsInstanceOf(clase)){
		stack->Push(1);
	}else{
		stack->Push(0);
	}
}