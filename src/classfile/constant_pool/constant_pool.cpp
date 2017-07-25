#include "constant_pool.hpp"
#include "constant_class_info.hpp"
#include "constant_double_info.hpp"
#include "constant_filedref_info.hpp"
#include "constant_float_info.hpp"
#include "constant_integer_info.hpp"
#include "constant_interfacemethodref_info.hpp"
#include "constant_invokedynamic_info.hpp"
#include "constant_long_info.hpp"
#include "constant_methodhandle_info.hpp"
#include "constant_methodref_info.hpp"
#include "constant_methodtype_info.hpp"
#include "constant_nameandtype_info.hpp"
#include "constant_string_info.hpp"
#include "constant_uft8_info.hpp"
#include <iostream>

using namespace jvm::classfile;

ConstantPool::~ConstantPool(){
	if (cp_.size() > 0){
		for (uint32 i = 1; i < cp_.size(); i++){
			if (cp_[i]){
				delete cp_[i];
			}
		}
	}
}

void ConstantPool::readConstantPool(jvm::util::ClassReader* rd){
	uint16 counts = rd->readUint16();
	cp_.resize(counts);

	if (counts > 0){
		cp_[0] = NULL;
	}
	
	for (uint32 i = 1; i < counts; i++){
		cp_[i] = __read_constant_nfo(rd);
		if (cp_[i]->getTag() == CONSTANT_INFO_TAG::CONSTANT_Double || cp_[i]->getTag() == CONSTANT_INFO_TAG::CONSTANT_Long){
			i++;			
			if (i < counts){
				cp_[i + 1] = NULL;
			}						
		}
	}
}

ConstantInfo* ConstantPool::__read_constant_nfo(jvm::util::ClassReader* rd){
	int8 tag = rd->readUint8();
	ConstantInfo* info = __new_constant_info(tag);
	info->setTag(tag);
	info->readInfo(rd);
	return info;
}

ConstantInfo* ConstantPool::__new_constant_info(uint8 tag){
	switch ((int32)tag){
	case CONSTANT_INFO_TAG::CONSTANT_Class:{
		 ConstantClassInfo* info = new ConstantClassInfo();
		 info->setConstantPool(this);
		 return info; }
	case CONSTANT_INFO_TAG::CONSTANT_Double:
		return new ConstantDoubleInfo(); 
	case CONSTANT_INFO_TAG::CONSTANT_Fieldref:{
		ConstantFiledrefInfo* field_ref = new ConstantFiledrefInfo();
		field_ref->setConstantPool(this);
		return field_ref; }
	case CONSTANT_INFO_TAG::CONSTANT_Float:{
		return new ConstantFloatInfo();
	}
	case CONSTANT_INFO_TAG::CONSTANT_Integer:
		return new ConstantIntegerInfo(); 
	case CONSTANT_INFO_TAG::CONSTANT_InterfaceMethodref:{
		ConstantInterfaceMethodrefInfo* imethodref = new ConstantInterfaceMethodrefInfo();
		imethodref->setConstantPool(this);
		return imethodref; }
	case CONSTANT_INFO_TAG::CONSTANT_InvokeDynamic:
		return new ConstantInvokeDynamicInfo(); 
	case CONSTANT_INFO_TAG::CONSTANT_Long:
		return new ConstantLongInfo(); 
	case CONSTANT_INFO_TAG::CONSTANT_MethodHandle:
		return new ConstantMethodHandleInfo();
	case CONSTANT_INFO_TAG::CONSTANT_Methodref:{
		 ConstantMethodrefInfo* method_ref = new ConstantMethodrefInfo();
		method_ref->setConstantPool(this);
		return method_ref; }
	case CONSTANT_INFO_TAG::CONSTANT_MethodType:
		return new ConstantMethodTypeInfo();
	case CONSTANT_INFO_TAG::CONSTANT_NameAndType:
		return new ConstantNameAndTypeInfo();
	case CONSTANT_INFO_TAG::CONSTANT_String:
		return new ConstantStringInfo();
	case CONSTANT_INFO_TAG::CONSTANT_Utf8:
		return new ConstantUtf8Info();
	default:
		std::cout << "create Constant Error, tag:" << tag << std::endl;
		break;
	}

	return NULL;
}



std::string ConstantPool::getUTF8(uint16 index){
	ConstantUtf8Info* tmp = (ConstantUtf8Info*)cp_[index];
	return tmp->toString();
}

std::string ConstantPool::getClassName(uint16 index){
	ConstantClassInfo* info = (ConstantClassInfo*)cp_[index];
	return info->getName();
}

ConstantInfo* ConstantPool::getConstantInfo(uint16 index){
	return cp_[index];
}

std::vector<std::string> ConstantPool::getNameAndType(uint16 index){
	ConstantNameAndTypeInfo *info = (ConstantNameAndTypeInfo*)getConstantInfo(index);
	std::vector<std::string> tmp;

	tmp.push_back(getUTF8(info->getNameIndex()));
	tmp.push_back(getUTF8(info->getDescriptorIndex()));

	return tmp;
}

uint16 ConstantPool::getConstantPoolSize(){
	return cp_.size();
}


std::vector<ConstantInfo*> ConstantPool::getConstantPool(){
	return cp_;
}
