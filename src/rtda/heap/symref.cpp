#include "symref.hpp"
#include <iostream>

using namespace jvm::rtda::heap;

void SymRef::__resolved_class(){
	Clase* d = cp_->getClase();
	Clase* c = d->clase_loader_->LoadClass(clase_name_);

	if (!c->isAccessibleTo(d)){
		std::cout << "java.lang.IllegalAccessError" << std::endl;
		return;
	}

	clase_ = c;
}


std::string SymRef::getClassName(){
	return clase_name_;
}

ConstantPool* SymRef::getConstant(){
	return cp_;
}

jvm::rtda::heap::Clase* SymRef::getClass(){
	return clase_;
}

jvm::rtda::heap::Clase* SymRef::ResolvedClass(){
	if (NULL == clase_){
		__resolved_class();
	}
	return clase_;
}