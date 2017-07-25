#ifndef __CONSTANT_UTF8_INFO_HPP_
#define __CONSTANT_UTF8_INFO_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"
#include <string>

namespace jvm{
	namespace classfile{
		class ConstantUtf8Info :public ConstantInfo{
		private:
			uint16 length_;
			int8* bytes_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				length_ = reader->readUint16();
				bytes_ = reader->readBytes((uint32)length_);
			}	

			std::string toString(){
				return std::string((int8*)bytes_, length_);
			}

			bool Equal(const int8* str){
				std::string  dst(str);
				std::string  src(bytes_, length_);

				if (dst == src){
					return true;
				}

				return false;
			}

			~ConstantUtf8Info(){
				if (bytes_){
					delete bytes_;
				}
			}
		};
	}
}


#endif