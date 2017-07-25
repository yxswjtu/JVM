#ifndef __CONSTANT_NAMEANDTYPE_INFO_HPP_
#define __CONSTANT_NAMEANDTYPE_INFO_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantNameAndTypeInfo :public ConstantInfo{
		private:
			uint16 name_index_;
			uint16 descriptor_index_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				name_index_ = reader->readUint16();
				descriptor_index_ = reader->readUint16();
			}
			uint16 getNameIndex(){
				return name_index_;
			}

			uint16 getDescriptorIndex(){
				return descriptor_index_;
			}
		};
	}
}



#endif