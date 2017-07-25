#ifndef __ATTRIBUTE_INFO_HPP_
#define __ATTRIBUTE_INFO_HPP_

#include "../../util/reader.hpp"
#include "../constant_pool/constant_pool.hpp"
#include "../../common/global.hpp"

namespace jvm{
	namespace classfile{
		class AttributeInfo {
		private:
			std::string attribute_name_;			
		public:		
			void setName(std::string&name){ attribute_name_ = name; }
			//get attribute name
			std::string getName(){ return attribute_name_; }
			virtual void readInfo(jvm::util::ClassReader* rd){}
		};
	}
}



#endif