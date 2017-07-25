#ifndef __CONSTANT_CLASS_INFO_HPP_
#define __CONSTANT_CLASS_INFO_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantClassInfo :public ConstantInfo{
		private:
			uint16 name_index_;
			ConstantPool* pool_;
		public:
			
			void readInfo(jvm::util::ClassReader* reader){
				name_index_ = reader->readUint16();
			}

			void setConstantPool(ConstantPool* pool){
				pool_ = pool;
			}

			std::string getName(){
				return pool_->getUTF8(name_index_);
			}

			uint16 getIndex(){
				return name_index_;
			}
		};

	}
}


#endif