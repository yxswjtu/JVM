#include "method_ref.hpp"

using namespace jvm::rtda::heap;

MethodRef::MethodRef(ConstantPool*cp, jvm::classfile::ConstantMethodrefInfo* info){
	cp_ = cp;
	copyMemberRefInfo(info);
}

Method* MethodRef::getMethod(){
	return method_;
}


Method* MethodRef::ResolvedMethod(){
	if (NULL == method_){
		__resolve_method_ref();
	}
	return method_;
}

// jvms8 5.4.3.3
void MethodRef::__resolve_method_ref(){
	//todo
}