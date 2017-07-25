#ifndef __CONSTANT_VALUE_ATTRIBUTE_HPP_
#define __CONSTANT_VALUE_ATTRIBUTE_HPP_

#include "attribute_info.hpp"

namespace jvm{
	namespace classfile{
		class ConstantValueAttribute :public AttributeInfo{
		private:
			uint16 constantvalue_index_;
		public:	
			
			void readInfo(jvm::util::ClassReader* rd){
				constantvalue_index_ = rd->readUint16();
			}

			uint16 getConstantValueIndex(){
				return constantvalue_index_;
			}
		};
	}
}
#endif