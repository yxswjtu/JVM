#ifndef __CLASS_LOADER_HPP_
#define __CLASS_LOADER_HPP_

#include "../../classfile/class_file.hpp"
#include <string>
#include <map>


namespace jvm{
	namespace rtda{
		namespace heap{
			class Clase;
			class Field;

			class ClaseLoader{
			private:
				std::string clase_path_;
				std::map <std::string, Clase*> clase_map_;
			private:
				Clase* __load_non_array_class(std::string& name);
				void __resolve_super_class(Clase* clase);
				void __resolve_interfaces(Clase* clase);
				void __link(Clase* clase);
				void __verify(Clase* clase);
				void __prepare(Clase* clase);
				void __calc_instance_field_slotids(Clase* clase);
				void __calc_static_field_slotids(Clase* clase);
				void __alloc_and_initstatic_vars(Clase* clase);
				void __init_static_final_var(Clase*clase, Field* field);
				//
				Clase* __define_class(jvm::classfile::ClassFile* file);
				jvm::classfile::ClassFile* __read_class(std::string& name);
			public:
				Clase* LoadClass(std::string& clase_name);
			};
		}
	}
}

#endif