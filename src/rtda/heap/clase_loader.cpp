#include "clase_loader.hpp"
#include "clase.hpp"
#include "field.hpp"
#include "../stack/slot.hpp"
#include <iostream>

using namespace jvm::rtda::heap;
using namespace jvm::classfile;

Clase* ClaseLoader::LoadClass(std::string& name){
	if (clase_map_.find(name) != clase_map_.end()){
		return clase_map_[name];
	}

	return __load_non_array_class(name);
}

ClassFile* ClaseLoader::__read_class(std::string& name){
	ClassFile *file = new ClassFile(name);
	file->Parse();
	return file;
}

Clase* ClaseLoader::__define_class(jvm::classfile::ClassFile* file){
	Clase* clase = new Clase(file);
	clase->clase_loader_ = this;
	__resolve_super_class(clase);
	__resolve_interfaces(clase);
	clase_map_.insert(std::map <std::string, Clase*>::value_type(file->getFileName(), clase));
	return clase;
}

Clase* ClaseLoader::__load_non_array_class(std::string& name){
	ClassFile *file = __read_class(name);
	Clase* clase = __define_class(file);	
	__link(clase);
	std::cout << "[Loaded class]:" << name << std::endl;
	return clase;
}

void ClaseLoader::__resolve_super_class(Clase* clase){
	if (clase->clase_name_ != std::string("java/lang/Object")) {
		//tricky
		//clase->super_class_ = clase->clase_loader_->LoadClass(clase->super_clase_name_);
		clase->super_class_ = clase->clase_loader_->LoadClass(std::string("./Object.class"));
	}
}

void  ClaseLoader::__resolve_interfaces(Clase* clase){
	uint32 len = clase->interface_names_.size();
	if (len > 0){
		clase->intrfaces_.resize(len);
		for (uint32 i = 0; i < len; i++){
			clase->intrfaces_[i] = clase->clase_loader_->LoadClass(clase->interface_names_[i]);
		}
	}
}

void ClaseLoader::__link(Clase* clase){
	__verify(clase);
	__prepare(clase);
}

void ClaseLoader::__verify(Clase* clase){
	std::cout << "begin to verify class:" << clase->clase_name_<<"..." << std::endl;
	std::cout << "verify class end" << std::endl;
}

void ClaseLoader::__prepare(Clase* clase){
	__calc_instance_field_slotids(clase);
	__calc_static_field_slotids(clase);
	__alloc_and_initstatic_vars(clase);
}

void ClaseLoader::__calc_instance_field_slotids(Clase* clase){
	uint32 slot_id = 0;
	if (clase->super_class_){
		slot_id = clase->super_class_->instance_slot_count_;
	}

	for (uint32 i = 0; i < clase->clase_fields_.size(); i++){		
		if (!clase->clase_fields_[i]->IsStatic()){			
			clase->clase_fields_[i]->setSlotId(slot_id);
			slot_id++;
			if (clase->clase_fields_[i]->IsLongOrDouble()){
				slot_id++;
			}
		}
	}
	clase->instance_slot_count_ = slot_id;
}
void ClaseLoader::__calc_static_field_slotids(Clase* clase){
	uint32 slot_id = 0;
	if (clase->super_class_){
		slot_id = clase->super_class_->instance_slot_count_;
	}

	for (uint32 i = 0; i < clase->clase_fields_.size(); i++){
		if (clase->clase_fields_[i]->IsStatic()){
			clase->clase_fields_[i]->setSlotId(slot_id);
			slot_id++;
			if (clase->clase_fields_[i]->IsLongOrDouble()){
				slot_id++;
			}
		}
	}
	clase->static_slot_count_ = slot_id;
}

void ClaseLoader::__alloc_and_initstatic_vars(Clase* clase){
	clase->static_vars_ = new Slot(clase->static_slot_count_);

	for (uint32 i = 0; i < clase->clase_fields_.size(); i++){
		if (clase->clase_fields_[i]->IsStatic() && clase->clase_fields_[i]->IsFinal()){
			__init_static_final_var(clase, clase->clase_fields_[i]);
		}
	}
}

void ClaseLoader::__init_static_final_var(Clase*clase, Field* field){
	Slot* stactic_vars = clase->static_vars_;
	ConstantPool* pool = clase->constant_pool_;

	uint32 const_index = field->getConstValueIndex();
	uint32 slot_id = field->getSlotId();
	std::string  descriptor = field->getDescriptor();

	if (const_index > 0){
		if (descriptor == std::string("Z") || descriptor == std::string("B") || descriptor == std::string("C") || \
			descriptor == std::string("S") || descriptor == std::string("I")){
			int32 val = getConstant<int32>(pool->getConstants(),const_index);
			stactic_vars->SetInt(slot_id, val);
		}else if (descriptor == std::string("J")){
			int64 val_long = getConstant<int64>(pool->getConstants(), const_index);
			stactic_vars->SetLong(slot_id, val_long);
		}
		else if (descriptor == std::string("F")){
			float32 val_float = getConstant<float32>(pool->getConstants(), const_index);
			stactic_vars->SetFloat(slot_id, val_float);
		}
		else if (descriptor == std::string("D")){
			float64 val_double = getConstant<float64>(pool->getConstants(), const_index);
			stactic_vars->SetDouble(slot_id, val_double);
		}
		else if (descriptor == std::string("Ljava/lang/String;")){
			std::cout << "Ljava/lang/String; todo" << std::endl;
		}
	}
}