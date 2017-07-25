#include "field_ref.hpp"
#include <iostream>

using namespace jvm::rtda::heap;

FieldRef::FieldRef(ConstantPool*cp, jvm::classfile::ConstantFiledrefInfo* refinfo){
	cp_ = cp;
	copyMemberRefInfo(refinfo);
}

Field* FieldRef::__lookup_field(Clase* c, std::string& name, std::string& descriptor){
	std::vector<Field*> clase_fields = c->clase_fields_;

	for (uint32 i = 0; i < clase_fields.size(); i++){
		if ((clase_fields[i]->getName() == name) && (clase_fields[i]->getDescriptor() == descriptor)){
			return clase_fields[i];
		}
	}

	std::vector<Clase*> interfaces = c->intrfaces_;
	for (uint32 j = 0; j < interfaces.size(); j++){
		Field* field = __lookup_field(interfaces[j], name, descriptor);
		if (field){
			return field;
		}
	}

	if (c->super_class_){
		return __lookup_field(c->super_class_, name, descriptor);
	}

	return NULL;
}

void FieldRef::__resolve_field_ref(){
	Clase* d = cp_->getClase();
	Clase* c = ResolvedClass();
	Field* field = __lookup_field(c, this->getName(), this->getDescriptor());

	if (NULL == field){
		std::cout << "java.lang.NoSuchFieldError" << std::endl;
		return;
	}

	if (!field->isAccessibleTo(d)){
		std::cout << "java.lang.IlegalAccessError" << std::endl;
		return;
	}

	field_ = field;
}

Field* FieldRef::ResolvedField(){
	if (NULL == field_){
		__resolve_field_ref();
	}
	return field_;
}

Field* FieldRef::getField(){
	return field_;
}