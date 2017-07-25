#ifndef __ATTRIBUTES_HPP_
#define __ATTRIBUTES_HPP_

#include "attribute_info.hpp"
#include "../../util/reader.hpp"
#include "../constant_pool/constant_pool.hpp"

namespace jvm{
	namespace classfile{
		class Attributes{
		private:
			AttributeInfo* __read_read_attribute(jvm::util::ClassReader* rd, ConstantPool* cp);
			AttributeInfo* __new_attribute_info(std::string&type, ConstantPool* cp, uint32 len);
		public:
			std::vector<AttributeInfo*> readAttributes(jvm::util::ClassReader* rd, ConstantPool* cp);
		};
	}
}
 

#endif