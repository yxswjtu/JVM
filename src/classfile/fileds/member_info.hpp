#ifndef __MEMBERONFO_HPP_
#define __MEMBERONFO_HPP_

#include "../../common/global.hpp"
#include "../constant_pool/constant_pool.hpp"
#include "../attributes/attribute_info.hpp"
#include "../attributes/code_attribute.hpp"
#include "../attributes/constant_value_attribute.hpp"
#include <vector>

namespace jvm{
	namespace classfile{
		class MemberInfo{
		private:
			ConstantPool* cp_;
			uint16        access_flag_;
			uint16        name_index_;
			uint16        descriptor_index_;
			std::vector<AttributeInfo*> attributes_;
		public:
			MemberInfo(ConstantPool* cp);
			//setter
			void setAccessFlag(uint16 flag);
			void setNameIndex(uint16 index);
			void setDescriptorIndex(uint16 index);
			void setAtrributes(std::vector<AttributeInfo*>& attri);
			//getter
			uint16 getAccessFlags();
			std::string	getName();
			std::string	getDescriptor();
			CodeAttribute* getCodeAtrribute();
			ConstantValueAttribute* getConstantValAtrribute();

			bool IsCodeAtrribute();
		};
	}
}



#endif