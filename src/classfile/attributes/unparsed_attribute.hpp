#ifndef __UNPARSED_ATRRIBUTE_HPP_
#define __UNPARSED_ATRRIBUTE_HPP_

/*
attribute_info {
u2 attribute_name_index;
u4 attribute_length;
u1 info[attribute_length];
}
*/

#include "attribute_info.hpp"

namespace jvm{
	namespace classfile{
		class UnparsedAttribute :public AttributeInfo{
		private:
			uint8* info_;
			uint32 length_;
			std::string name_;
		public:
			UnparsedAttribute(std::string &name,uint32 length){
				length_ = length;
				name_ = name;
			}

			void readInfo(jvm::util::ClassReader* rd){
				info_ = (uint8*)rd->readBytes(length_);
			}			

			~UnparsedAttribute(){
				if (info_){
					delete info_;
				}
			}
		};

	}
}


#endif