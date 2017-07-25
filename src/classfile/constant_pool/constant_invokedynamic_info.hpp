#ifndef __CONSTANT_INVOKEDYNAMIC_INFO_HPP_
#define __CONSTANT_INVOKEDYNAMIC_INFO_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantInvokeDynamicInfo :public ConstantInfo{
		private:
			uint16  bootstrap_method_attrIndex_;
			uint16  name_and_type_index_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				bootstrap_method_attrIndex_ = reader->readUint16();
				name_and_type_index_ = reader->readUint16();
			}
		};
	}
}
#endif