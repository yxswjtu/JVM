#ifndef __MEMBERREF_HPP_
#define __MEMBERREF_HPP_

#include "symref.hpp"
#include "../../classfile/constant_pool/constant_ref_info.hpp"

namespace jvm{
	namespace rtda{
		namespace heap{
			class MemberRef :public SymRef{
			private:
				std::string name_;
				std::string descriptor_;
			public:
				
				void copyMemberRefInfo(jvm::classfile::ConstantRefInfo* info){
					this->clase_name_ = info->getClassName();

					std::vector<std::string> name_type = info->getNameAndType();
					name_ = name_type[0];
					descriptor_ = name_type[1];
				}

				std::string getName(){
					return name_;
				}

				std::string getDescriptor(){
					return descriptor_;
				}
			};
		}
	}
}

#endif