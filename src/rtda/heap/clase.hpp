#ifndef __CLASE_HPP_
#define __CLASE_HPP_

#include "../../common/global.hpp"
#include "../../classfile/class_file.hpp"
#include "../stack/slot.hpp"
#include "clase_loader.hpp"
#include "constant_pool.hpp"


namespace jvm{
	namespace rtda{
		namespace heap{
			class Field;
			class Method;
			class Object;
			class Clase{						
			public:
				uint16 access_flag_;
				std::string       clase_name_;
				std::string    super_clase_name_;
				std::vector<std::string> interface_names_;
				//ConstantPool*   constant_pool_;
				ConstantPool * constant_pool_;
				std::vector<Field*> clase_fields_;
				std::vector<Method*> clase_methods_;
				ClaseLoader*     clase_loader_;
				Clase*           super_class_;
				std::vector<Clase*>  intrfaces_;
				uint16 instance_slot_count_;
				uint16 static_slot_count_;
				Slot*      static_vars_;

				jvm::classfile::ClassFile*   clase_file_;
				Clase(jvm::classfile::ClassFile* file);
				~Clase();

				//
				Object* NewObject();
				//
				std::string getPackageName();
				Slot* getStaticVars();
				ConstantPool * getConstantPool();
				bool isAccessibleTo(Clase* other);
				bool IsSubClassOf(Clase* other);
				bool IsPublic();
				bool IsInterface();
				bool IsAbstract();
				//
				Method* getStaticMethod(std::string&name, std::string& descriptor);
				Method* getMainMethod();
			};
		}
	}
}

#endif