#include "code_attribute.hpp"
#include "attributes.hpp"
#include "../class_file.hpp"

using namespace jvm::classfile;

CodeAttribute::~CodeAttribute(){
	if (code_){
		delete[] code_;
	}

	std::vector<ExceptionEntry*>::iterator ex_it = exception_table_.begin();
	for (; ex_it != exception_table_.end(); ex_it++){
		delete (*ex_it);
	}
}

CodeAttribute::CodeAttribute(ConstantPool* cp){
	code_ = NULL;
	cp_ = cp;
}

void CodeAttribute::readInfo(jvm::util::ClassReader* rd){
	max_stack_ = rd->readUint16();
	max_locals_ = rd->readUint16();

	code_length_ = rd->readUint32();
	code_ = (uint8*)rd->readBytes(code_length_);
	__read_exception_table(rd);
	attributs_ = attributs_reader_.readAttributes(rd, cp_);
}

void CodeAttribute::__read_exception_table(jvm::util::ClassReader* rd){
	uint16 len = rd->readUint16();
	exception_table_.resize(len);

	for (uint16 i = 0; i < len; i++){
		exception_table_[i] = new ExceptionEntry(rd);
	}
}

uint16 CodeAttribute::getMaxStack(){
	return max_stack_;
}

uint16 CodeAttribute::getMaxLocals(){
	return max_locals_;
}

uint8* CodeAttribute::getCode(){
	return code_;
}

uint32 CodeAttribute::getCodeLength(){
	return code_length_;
}

std::vector<ExceptionEntry*> CodeAttribute::getExceptionTable(){
	return exception_table_;
}

