#include "class_file.hpp"
#include "./constant_pool/constant_class_info.hpp"
#include <iostream>

using namespace jvm::classfile;
using namespace jvm::util;

ClassFile::ClassFile(std::string& name) :file_name_(name){
	interfaces_ = NULL;
}

ClassFile::~ClassFile(){
	if (interfaces_){
		delete interfaces_;
	}

	std::vector<MemberInfo*>::iterator it_field = fields_.begin();
	for (; it_field != fields_.end(); it_field++){
		delete *it_field;
	}

	std::vector<MemberInfo*>::iterator it = methods_.begin();
	for (; it != methods_.end(); it++){
		delete *it;
	}

	std::vector<AttributeInfo*>::iterator it_attr = attributes_.begin();
	for (; it_attr != attributes_.end(); it_attr++){
		delete *it_attr;
	}

	delete reader_;
}

void ClassFile::__read_and_check_magic(){
	magic_number_ =	reader_->readUint32();
	if (magic_number_ != 0xCAFEBABE){
		std::cout << "java.lang.ClassFormatError: magic!" << std::endl;
	}
}

void ClassFile::__read_and_check_version(){
	minor_version_ = reader_->readUint16();
	major_version_ = reader_->readUint16();
	switch (major_version_){
		case 45:
			return;
		case 46:
		case 47:
		case 48:
		case 49:
		case 50:
		case 51:
		case 52:
			if (minor_version_ == 0) {
				return;
			}
	}
	std::cout << "java.lang.UnsupportedClassVersionError!" << std::endl;
}

void ClassFile::Parse(){
	//open file and read contents
	std::ifstream fd(file_name_, std::ios::binary);
	if (!fd.is_open()){
		std::cout << "open class file failed!" << std::endl;
		return;
	}
	//get the length of contents in bytes
	int32 length = 0;
	fd.seekg(0, std::ios::end);
	length = (int32)fd.tellg();
	fd.seekg(0);
	//read the data into buffer
	int8* buf = new int8[length];
	memset(buf, 0, length);
	fd.read(buf, length);
	fd.close();
	//new ClassReader to parse the contents
	reader_ = new ClassReader(buf, length);

	__read_and_check_magic();
	__read_and_check_version();
	
	//get constant pool
	constant_pool_.readConstantPool(reader_);
	//get access_flag
	access_flag_ = reader_->readUint16();
	//get index of this class in constant pool
	this_class_ = reader_->readUint16();
	//get index of super class in constant pool
	super_class_ = reader_->readUint16();
	//get the interface
	interfaces_ = reader_->readUint16s(&interfaces_count_);
	//get fields and methods
	__read_field_members();
	__read_method_members();
	//get attributes
	attributes_ = attributes_reader_.readAttributes(reader_, &constant_pool_);
	
	delete buf;
}

void ClassFile::__read_method_members(){
	uint16 counts = reader_->readUint16();

	methods_.resize(counts);
	for (uint16 i = 0; i < counts; i++){
		methods_[i] = __read_member();
	}
}

void ClassFile::__read_field_members(){
	uint16 counts = reader_->readUint16();

	fields_.resize(counts);
	for (uint16 i = 0; i < counts; i++){
		fields_[i] = __read_member();
	}
}


MemberInfo* ClassFile::__read_member(){
	MemberInfo* member = new MemberInfo(&constant_pool_);

	member->setAccessFlag(reader_->readUint16());
	member->setNameIndex(reader_->readUint16());
	member->setDescriptorIndex(reader_->readUint16());
	member->setAtrributes(attributes_reader_.readAttributes(reader_, &constant_pool_));

	return member;
}

std::vector<MemberInfo*> ClassFile::getMethods(){
	return methods_;
}

std::vector<MemberInfo*> ClassFile::getFields(){
	return fields_;
}

std::string ClassFile::getClassName(){
	std::vector<ConstantInfo*> infos = constant_pool_.getConstantPool();
	ConstantClassInfo *info = (ConstantClassInfo*)infos[this_class_];
	return constant_pool_.getUTF8(info->getIndex());
}

std::string ClassFile::getSuperClassName(){
	std::vector<ConstantInfo*> infos = constant_pool_.getConstantPool();
	ConstantClassInfo *info = (ConstantClassInfo*)infos[super_class_];
	if (info){
		return constant_pool_.getUTF8(info->getIndex());
	}
	return std::string("no super class");
}

std::vector<std::string> ClassFile::getInterfaceNames(){
	std::vector<std::string> tmp;
	std::vector<ConstantInfo*> infos = constant_pool_.getConstantPool();

	if (interfaces_ && (interfaces_count_ > 0)){
		tmp.resize(interfaces_count_);
		for (int i = 0; i < interfaces_count_; i++){
			ConstantClassInfo *info = (ConstantClassInfo*)infos[interfaces_[i]];
			tmp[i] = constant_pool_.getUTF8(info->getIndex());
		}
	}

	return tmp;
}


