#ifndef __SOURCE_FILE_ATRRIBUTE_HPP_
#define __SOURCE_FILE_ATRRIBUTE_HPP_

#include "attribute_info.hpp"


namespace jvm{
	namespace classfile{
		class SourcefileAtrribute :public AttributeInfo{
		private:
			uint16 sourcefile_index_;
		public:	
			void readInfo(jvm::util::ClassReader* rd){
				sourcefile_index_ = rd->readUint16();
			}

			std::string getFileName(ConstantPool* cp){
				return cp->getUTF8(sourcefile_index_);
			}
		};
	}
}



#endif