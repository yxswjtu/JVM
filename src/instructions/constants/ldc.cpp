#include "ldc.hpp"
#include "../../rtda/heap/object.hpp"
#include "../../rtda/heap/clase.hpp"
#include "../../rtda/heap/clase_ref.hpp"

#include <iostream>

using namespace jvm::instruction;
using namespace jvm::rtda::heap;

void __ldc(Frame* frame, uint32 index) {
	OperandStack* stack = frame->GetOperandStack();
	ConstantPool *cp = frame->getMethod()->getClase()->getConstantPool();
	std::vector<jvm::classfile::CONSTANT_INFO_TAG> types = cp->getConstantType();
	jvm::classfile::CONSTANT_INFO_TAG type = types[index];

	 switch (type) {
	 case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Integer:
		 stack->Push(getConstant<int32>(cp->getConstants(),index));
		 break;
	 case  jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Float:
		 stack->Push(getConstant<float32>(cp->getConstants(),index));
		 break;
			 // case string:
			 // case *heap.ClassRef:
			 // case MethodType, MethodHandle
	 default:
		 std::cout << "todo: ldc!" << std::endl;
	 }
}

void LDC::Execute(Frame* frame){
	__ldc(frame, getIndex());
}

void LDC_W::Execute(Frame* frame){
	__ldc(frame, getIndex());
}

void LDC2_W::Execute(Frame* frame){
	OperandStack* stack = frame->GetOperandStack();
	ConstantPool *cp = frame->getMethod()->getClase()->getConstantPool();
	std::vector<jvm::classfile::CONSTANT_INFO_TAG> types = cp->getConstantType();
	jvm::classfile::CONSTANT_INFO_TAG type = types[getIndex()];

	switch (type) {
	case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Long:
		stack->Push(getConstant<int64>(cp->getConstants(),getIndex()));
		break;
	case  jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Double:
		stack->Push(getConstant<float64>(cp->getConstants(),getIndex()));
		break;
		// case string:
		// case *heap.ClassRef:
		// case MethodType, MethodHandle
	default:
		std::cout << "java.lang.ClassFormatError" << std::endl;
	}
}