#ifndef __CONSTANT_POOL_HPP_
#define __CONSTANT_POOL_HPP_


#include "constant_info.hpp"
#include "../../util/reader.hpp"
#include <vector>

namespace jvm{
	namespace classfile{
		class ConstantPool{
		private:			
			std::vector<ConstantInfo*> cp_;
		private:
			ConstantInfo* __read_constant_nfo(jvm::util::ClassReader* rd);
			ConstantInfo* __new_constant_info(uint8 tag);
		public:
			ConstantPool(){}
			~ConstantPool();
			//read constantpool from strstream
			void readConstantPool(jvm::util::ClassReader* rd);

			//some getter
			std::vector<ConstantInfo*> getConstantPool();
			uint16 getConstantPoolSize();

			// Requesting information	
			ConstantInfo* getConstantInfo(uint16 index);
			std::string getUTF8(uint16 index);
			std::string getClassName(uint16 index);
			std::vector<std::string> getNameAndType(uint16 index);
		};
	}
}
#endif
