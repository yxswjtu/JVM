#ifndef __CONSTANT_METHODTYPE_INFO_HPP_
#define __CONSTANT_METHODTYPE_INFO_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantMethodTypeInfo :public ConstantInfo{
		private:
			uint16 descriptor_index_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				descriptor_index_ = reader->readUint16();
			}
		};
	}
}


#endif