#ifndef __CONSTANT_STRING_HPP_
#define __CONSTANT_STRING_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantStringInfo :public ConstantInfo{
		private:
			uint16 index_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				index_ = reader->readUint16();
			}			
			uint16 getIndex(){
				return index_;
			}

			std::string toString(ConstantPool* pool){
				return pool->getUTF8(index_);
			}
		};
	}
}



#endif