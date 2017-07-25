#ifndef __CONSTANT_REF_INFO_HPP_
#define __CONSTANT_REF_INFO_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantRefInfo :public ConstantInfo{
		private:
			uint16 class_index_;
			uint16 name_and_type_index_;
			ConstantPool* pool_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				class_index_ = reader->readUint16();
				name_and_type_index_ = reader->readUint16();
			}

			void setConstantPool(ConstantPool* pool){
				pool_ = pool;
			}		

			std::vector<std::string> getNameAndType(){
				return pool_->getNameAndType(name_and_type_index_);
			}

			std::string getClassName(){
				return pool_->getClassName(class_index_);
			}
		};
	}
}



#endif