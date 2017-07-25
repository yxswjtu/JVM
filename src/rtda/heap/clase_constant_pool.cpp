#include "constant_pool.hpp"
#include "../../classfile/constant_pool/constants.hpp"
#include "clase_ref.hpp"
#include "field_ref.hpp"
#include "method_ref.hpp"
#include "interface_method.hpp"
#include <iostream>


using namespace jvm::rtda::heap;

ConstantPool::~ConstantPool(){
	for (uint32 i = 1; i < constants_.size(); i++){

		if (constants_type_[i] == jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Class){
			delete constants_[i]->any_cast<ClaseRef*>();
			delete constants_[i];
		}
		else if (constants_type_[i] == jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Fieldref){
			delete constants_[i]->any_cast<FieldRef*>();
			delete constants_[i];
		}
		else if (constants_type_[i] == jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Methodref){
			delete constants_[i]->any_cast<MethodRef*>();
			delete constants_[i];
		}
		else if (constants_type_[i] == jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_InterfaceMethodref){
			delete constants_[i]->any_cast<InterfaceMethodRef*>();
			delete constants_[i];
		}
		else{
			delete constants_[i];
		}
	}
}

ConstantPool::ConstantPool(Clase* clase, jvm::classfile::ConstantPool* pool){
	clase_ = clase;
	__copy_constant_pool(pool);
}

Clase* ConstantPool::getClase(){
	return clase_;
}

std::vector<Any*>& ConstantPool::getConstants(){
	return constants_;
}

std::vector<jvm::classfile::CONSTANT_INFO_TAG> ConstantPool::getConstantType(){
	return constants_type_;
}

void ConstantPool::__copy_constant_pool(jvm::classfile::ConstantPool* pool){
	std::vector<jvm::classfile::ConstantInfo*> infos = pool->getConstantPool();

	constants_.resize(infos.size());
	constants_[0] = (Any*)NULL;

	constants_type_.resize(infos.size());
	constants_type_[0] = (jvm::classfile::CONSTANT_INFO_TAG)-1;

	for (uint32 i = 1; i < infos.size(); i++){
		jvm::classfile::ConstantInfo* info = infos[i];
		
		switch ((jvm::classfile::CONSTANT_INFO_TAG)info->getTag()){
			std::cout << info->getTag() << std::endl;
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Integer:{
			jvm::classfile::ConstantIntegerInfo* tmp1 = (jvm::classfile::ConstantIntegerInfo*)info;
			constants_[i] = new Any(tmp1->getValue());
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Integer;
			break; }
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Float:{
			jvm::classfile::ConstantFloatInfo* tmp2 = (jvm::classfile::ConstantFloatInfo*)info;
			constants_[i] = new Any(tmp2->getValue());
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Float;
			break;}
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Double:{
			jvm::classfile::ConstantDoubleInfo* tmp3 = (jvm::classfile::ConstantDoubleInfo*)info;
			constants_[i] = new Any(tmp3->getValue());
			i++;
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Double;
			break; }
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Long:{
			jvm::classfile::ConstantLongInfo* tmp4 = (jvm::classfile::ConstantLongInfo*)info;
			constants_[i] = new Any(tmp4->getValue());
			i++;
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Long;
			break; }
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_String:{
			jvm::classfile::ConstantStringInfo* tmp5 = (jvm::classfile::ConstantStringInfo*)info;
			constants_[i] = new Any(pool->getUTF8(tmp5->getIndex()));
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_String;
			break; }
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Class:	{
			ClaseRef* cref = new ClaseRef(this, (jvm::classfile::ConstantClassInfo*)info);
			constants_[i] = new Any(cref);
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Class;
			break;}
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Fieldref:{
			FieldRef* fref = new FieldRef(this, (jvm::classfile::ConstantFiledrefInfo*)info);
			constants_[i] = new Any(fref);
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Fieldref;
			break; }
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Methodref:{
			MethodRef* mref = new MethodRef(this, (jvm::classfile::ConstantMethodrefInfo*)info);
			constants_[i] = new Any(mref);
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_Methodref;
			break; }
		case jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_InterfaceMethodref:{
			InterfaceMethodRef* iref = new InterfaceMethodRef(this, (jvm::classfile::ConstantInterfaceMethodrefInfo*)info);
			constants_[i] = new Any(iref);
			constants_type_[i] = jvm::classfile::CONSTANT_INFO_TAG::CONSTANT_InterfaceMethodref;
			break; }
		default:
			constants_type_[i] = (jvm::classfile::CONSTANT_INFO_TAG) - 1;
			std::cout << "unkown constant pool item" << std::endl;
			break;
		}

	}
}