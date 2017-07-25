#include "new.hpp"
#include "../../rtda/heap/constant_pool.hpp"
#include "../../rtda/heap/clase.hpp"
#include "../../rtda/heap/clase_ref.hpp"
#include <iostream>

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void New::Execute(Frame* frame){
	ConstantPool* pool = frame->getMethod()->getClase()->constant_pool_;
	ClaseRef* clase_ref = getConstant<ClaseRef*>(pool->getConstants(), getIndex());
	Clase* clase = clase_ref->ResolvedClass();

	if (clase->IsInterface() || clase->IsAbstract()){
		std::cout << "java.lang.InstantiationError" << std::endl;
		return;
	}

	Object* obj = clase->NewObject();
	frame->GetOperandStack()->Push(obj);
}



