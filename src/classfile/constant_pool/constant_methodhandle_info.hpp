#ifndef __CONSTANT_METHODHANDLE_INFO_HPP_
#define __CONSTANT_METHODHANDLE_INFO_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantMethodHandleInfo :public ConstantInfo{
		private:
			uint8  reference_kind_;
			uint16  reference_index_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				reference_kind_ = reader->readUint8();
				reference_index_ = reader->readUint16();
			}			
		};
	}
}


#endif