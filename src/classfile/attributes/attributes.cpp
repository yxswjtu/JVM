#include "attributes.hpp"
#include "code_attribute.hpp"
#include "constant_value_attribute.hpp"
#include "deprecated_attribute.hpp"
#include "exception_attribute.hpp"
#include "linenumber_table_attribute.hpp"
#include "local_variable_table_attribute.hpp"
#include "sourcefile_attribute.hpp"
#include "synthtic_attribute.hpp"
#include "unparsed_attribute.hpp"

using namespace jvm::classfile;

AttributeInfo* Attributes::__read_read_attribute(jvm::util::ClassReader* rd, ConstantPool* cp){
	uint16 name_index = rd->readUint16();
	std::string name = cp->getUTF8(name_index);
	uint32 attr_len = rd->readUint32();

	AttributeInfo* info = __new_attribute_info(name, cp, attr_len);
	info->setName(cp->getUTF8(name_index));
	info->readInfo(rd);

	return info;
}

std::vector<AttributeInfo*> Attributes::readAttributes(jvm::util::ClassReader* rd, ConstantPool* cp){
	uint16 counts = rd->readUint16();

	std::vector<AttributeInfo*> attributes;
	attributes.resize(counts);

	for (uint16 i = 0; i < counts; i++){
		attributes[i] = __read_read_attribute(rd,cp);
	}

	return attributes;
}

AttributeInfo* Attributes::__new_attribute_info(std::string&type, ConstantPool* cp, uint32 len){
	if (type == std::string("Code")){
		return new CodeAttribute(cp);
	}
	else if (type == std::string("ConstantValue")){
		return new ConstantValueAttribute();
	}
	else if (type == std::string("Deprecated")){
		return new DeprecatedAttribute();
	}
	else if (type == std::string("Exceptions")){
		return new ExceptionAttribute();
	}
	else if (type == std::string("LineNumberTable")){
		return new LinenumberTableAttribute();
	}
	else if (type == std::string("LocalVariableTable")){
		return new LocalvariableTableAttribute();
	}
	else if (type == std::string("SourceFile")){
		return new SourcefileAtrribute();
	}
	else if (type == std::string("Synthetic")){
		return new SynthticAttribute();
	}

	return new UnparsedAttribute(type, len);
}