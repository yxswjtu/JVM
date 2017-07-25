#include "interface_method.hpp"

using namespace jvm::rtda::heap;

// jvms8 5.4.3.4
void InterfaceMethodRef::__resolve_interface_method_ref(){
	//todo
}

InterfaceMethodRef::InterfaceMethodRef(ConstantPool*cp, jvm::classfile::ConstantInterfaceMethodrefInfo* info){
	cp_ = cp;
	copyMemberRefInfo(info);
}

Method* InterfaceMethodRef::getMethod(){
	return method_;
}

Method* InterfaceMethodRef::ResolvedInterfaceMethod(){
	if (NULL == method_){
		__resolve_interface_method_ref();
	}

	return method_;
}