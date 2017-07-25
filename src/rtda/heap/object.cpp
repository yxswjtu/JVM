#include "object.hpp"

using namespace jvm::rtda::heap;

Slot* Object::getFields(){
	return fields_;
}

Clase* Object::getClass(){
	return clase_;
}

void Object::setClass(Clase* clase){
	clase_ = clase;
}

void Object::setFields(Slot* field){
	fields_ = field;
}

bool Object::IsInstanceOf(Clase* clase){
	//return class.isAssignableFrom(self.class)
	return false;
}