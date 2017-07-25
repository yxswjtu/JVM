#include "member_info.hpp"

using namespace jvm::classfile;

MemberInfo::MemberInfo(ConstantPool* cp){
	cp_ = cp;
}

void MemberInfo::setAccessFlag(uint16 flag){
	access_flag_ = flag;
}
void MemberInfo::setNameIndex(uint16 index){
	name_index_ = index;
}

void MemberInfo::setDescriptorIndex(uint16 index){
	descriptor_index_ = index;
}

void MemberInfo::setAtrributes(std::vector<AttributeInfo*>& attri){
	attributes_ = attri;
}

std::string	MemberInfo::getName(){
	return cp_->getUTF8(name_index_);
}

uint16 MemberInfo::getAccessFlags(){
	return access_flag_;
}

std::string	MemberInfo::getDescriptor(){
	return cp_->getUTF8(descriptor_index_);
}

CodeAttribute* MemberInfo::getCodeAtrribute(){
	std::vector<AttributeInfo*>::iterator it;

	for (it = attributes_.begin(); it != attributes_.end(); it++){
		if ((*it)->getName() == std::string("Code")){
			return (CodeAttribute*)(*it);
		}
	}

	return NULL;
}

ConstantValueAttribute* MemberInfo::getConstantValAtrribute(){
	std::vector<AttributeInfo*>::iterator it;

	for (it = attributes_.begin(); it != attributes_.end(); it++){
		if ((*it)->getName() == std::string("ConstantValue")){
			return (ConstantValueAttribute*)(*it);
		}
	}

	return NULL;
}

bool MemberInfo::IsCodeAtrribute(){
	if (std::string("Code") == getName()){
		return true;
	}

	return false;
}