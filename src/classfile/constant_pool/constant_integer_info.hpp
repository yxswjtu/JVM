#ifndef __CONSTANT_INTEGER_HPP_
#define __CONSTANT_INTEGER_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantIntegerInfo :public ConstantInfo{
		private:
			int32 value_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				value_ = (int32)reader->readUint32();
			}

			int32 getValue(){				
				return value_;
			}
		};
	}
}



#endif