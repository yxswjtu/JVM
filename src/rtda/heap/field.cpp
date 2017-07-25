#include "field.hpp"

using namespace jvm::rtda::heap;

Field::Field(){
	const_value_index_ = -1;
	slot_id_ = 0;
}

bool Field::IsLongOrDouble(){
	if ((getDescriptor() == std::string("J")) || (getDescriptor() == std::string("D"))){
		return true;
	}
	return false;
}

uint16  Field::getSlotId(){
	return slot_id_;
}

void Field::setSlotId(uint16 sid){
	slot_id_ = sid;
}

uint16 Field::getConstValueIndex(){
	return const_value_index_;
}

bool Field::IsVolatile(){
	return (0 != (getAccessFlags() & ACC_VOLATILE));
}

bool Field::IsTransient(){
	return 0 != (getAccessFlags() & ACC_TRANSIENT);
}

bool Field::IsEnum(){
	return 0 != (getAccessFlags() & ACC_ENUM);
}

std::vector<Field*> Field::newFields(Clase* clase, std::vector<jvm::classfile::MemberInfo*>& cfields){
	std::vector<jvm::classfile::MemberInfo*>::iterator it;
	std::vector<Field*> fields;

	fields.reserve(cfields.size());
	for (it = cfields.begin(); it != cfields.end(); it++){
		Field* field = new Field();
		field->setClase(clase);
		field->copyMemberInfo(*it);		
		field->copyAttributes(*it);
		fields.push_back(field);
	}

	return fields;
}

void Field::copyAttributes(jvm::classfile::MemberInfo* info){
	if (info->getConstantValAtrribute()){
		const_value_index_ = info->getConstantValAtrribute()->getConstantValueIndex();
	}	
}

