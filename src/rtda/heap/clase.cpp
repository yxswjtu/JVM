#include "clase.hpp"
#include"../stack/slot.hpp"
#include "../heap/object.hpp"
#include "field.hpp"
#include "method.hpp"

using namespace jvm::rtda::heap;
using namespace jvm::classfile;

Clase::Clase(ClassFile* file):clase_file_(file){
	access_flag_ = file->getAccessFlag();
	clase_name_ = file->getClassName();
	super_clase_name_ = file->getSuperClassName();
	interface_names_ = file->getInterfaceNames();

	static_vars_ = NULL;
	constant_pool_ = new ConstantPool(this, file->getConstantPool());
	
	Field field;
	clase_fields_ = field.newFields(this, file->getFields());
	
	Method method;
	clase_methods_ = method.newFields(this, file->getMethods());
}

Clase::~Clase(){

	std::vector<Field*>::iterator it1;
	for (it1 = clase_fields_.begin(); it1 != clase_fields_.end(); it1++){
		delete (*it1);
	}

	std::vector<Method*>::iterator it2;
	for (it2 = clase_methods_.begin(); it2 != clase_methods_.end(); it2++){
		delete (*it2);
	}

	if (clase_file_){
		delete clase_file_;
	}

	if (constant_pool_){
		delete constant_pool_;
	}

	if (static_vars_){
		delete static_vars_;
	}
}

Object* Clase::NewObject(){
	//todo
	Object* obj = new Object();	
	obj->setClass(this);
	Slot*   slots = new Slot(instance_slot_count_);
	obj->setFields(slots);
	return obj;
}

bool Clase::IsInterface(){
	return 0 != (access_flag_ & ACC_INTERFACE);
}

bool Clase::IsAbstract(){
	return 0 != (access_flag_ & ACC_ABSTRACT);
}

bool Clase::isAccessibleTo(Clase* cls){
	if (cls->IsPublic() || (cls->getPackageName() == getPackageName()) ){
		return true;
	}
	return false;
}

bool Clase::IsSubClassOf(Clase* other){
	if (super_clase_name_ == other->clase_name_){
		return true;
	}
	return false;
}

bool Clase::IsPublic(){
	return 0 != (access_flag_ & ACC_PUBLIC);
}

std::string Clase::getPackageName(){	
	return clase_name_.substr(0, clase_name_.find_last_of('/'));
}

Slot* Clase::getStaticVars(){
	return static_vars_;
}

jvm::rtda::heap::ConstantPool* Clase::getConstantPool(){
	return constant_pool_;
}

Method* Clase::getStaticMethod(std::string&name, std::string& descriptor){
	for (unsigned int i = 0; i < clase_methods_.size(); i++){
		if (clase_methods_[i]->IsStatic()){
			if (name == clase_methods_[i]->getName() && descriptor == clase_methods_[i]->getDescriptor()){
				return clase_methods_[i];
			}
		}
	}

	return NULL;
}

Method* Clase::getMainMethod(){
	return getStaticMethod(std::string("main"), std::string("([Ljava/lang/String;)V"));
}
