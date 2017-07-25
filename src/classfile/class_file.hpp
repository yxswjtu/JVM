#ifndef __CLASS_FILE_HPP_
#define __CLASS_FILE_HPP_
/*
ClassFile {
u4             magic;
u2             minor_version;
u2             major_version;
u2             constant_pool_count;
cp_info        constant_pool[constant_pool_count-1];
u2             access_flags;
u2             this_class;
u2             super_class;
u2             interfaces_count;
u2             interfaces[interfaces_count];
u2             fields_count;
field_info     fields[fields_count];
u2             methods_count;
method_info    methods[methods_count];
u2             attributes_count;
attribute_info attributes[attributes_count];
}
*/
#include "../util/reader.hpp"
#include "constant_pool/constant_pool.hpp"
#include "./fileds/member_info.hpp"
#include "./attributes/attributes.hpp"
#include <vector>
#include <string>

namespace jvm{
	namespace classfile{
		class ClassFile {			
		private:
			uint32   magic_number_;
			uint16 minor_version_;
			uint16 major_version_;
			ConstantPool   constant_pool_;
			uint16 access_flag_;
			uint16 this_class_;
			uint16 super_class_;
			uint16 interfaces_count_;
			uint16* interfaces_;			
			std::vector<MemberInfo*> fields_;			
			std::vector<MemberInfo*> methods_;
			std::vector<AttributeInfo*> attributes_;

			const std::string  file_name_;
			jvm::util::ClassReader* reader_;
			Attributes attributes_reader_;
		private:
			void __read_and_check_magic();
			void __read_and_check_version();

			void __read_field_members();
			void __read_method_members();
			MemberInfo* __read_member();				
		public:
			ClassFile(std::string& name);
			virtual ~ClassFile();

			//analysis data from *.class
			void Parse(void);				

			//getter
			ConstantPool* getConstantPool(){
				return &constant_pool_;
			}	

			std::string getFileName(){
				return file_name_;
			}

			std::vector<MemberInfo*> getMethods();
			std::vector<MemberInfo*> getFields();

			std::string getClassName();
			std::string getSuperClassName();
			std::vector<std::string> getInterfaceNames();

			uint16 getAccessFlag(){
				return access_flag_;
			}

		};
	}
}


#endif /* CLASSFILE_H_ */
