#include "method.hpp"
#include "../../classfile/attributes/code_attribute.hpp"

using namespace jvm::rtda::heap;

bool  Method::IsSynchronized(){
	return 0 != (getAccessFlags() & ACC_SYNCHRONIZED);
}

bool  Method::IsBridge(){
	return 0 != (getAccessFlags() & ACC_BRIDGE);
}

bool  Method::IsVarargs(){
	return 0 != (getAccessFlags() & ACC_VARARGS);
}

bool  Method::IsNative(){
	return 0 != (getAccessFlags() & ACC_NATIVE);
}

bool  Method::IsAbstract(){
	return 0 != (getAccessFlags() & ACC_ABSTRACT);
}

bool  Method::IsStrict(){
	return 0 != (getAccessFlags() & ACC_STRICT);
}

uint32  Method::getMaxStack(){
	return max_stack_;
}

uint32 Method::getMaxLocals(){
	return max_locals_;
}

uint8*  Method::getCode(){
	return code_;
}

Method::~Method(){
	if (code_){
		delete code_;
	}
}

Method::Method(){
	code_ = NULL;
}

std::vector<Method*> Method::newFields(Clase* clase, std::vector<jvm::classfile::MemberInfo*>& cmethods){
	std::vector<jvm::classfile::MemberInfo*>::iterator it;
	std::vector<Method*> methods;

	methods.reserve(cmethods.size());
	for (it = cmethods.begin(); it != cmethods.end(); it++){
		Method* method = new Method();
		method->setClase(clase);
		method->copyMemberInfo(*it);
		method->copyAtrributes(*it);
		methods.push_back(method);
	}

	return methods;
}

void Method::copyAtrributes(jvm::classfile::MemberInfo* info){	
	jvm::classfile::CodeAttribute* code = info->getCodeAtrribute();
	if (code){
		max_stack_ = code->getMaxStack();
		max_locals_ = code->getMaxLocals();
		code_ = new uint8[code->getCodeLength()];
		code_length_ = code->getCodeLength();
		memcpy(code_, code->getCode(), code_length_);
	}			
}