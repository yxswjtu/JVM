#ifndef __CONSTANT_FLOAT_HPP_
#define __CONSTANT_FLOAT_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantFloatInfo :public ConstantInfo{
		private:
			float32 value_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				value_ = reader->readFloat32();
			}

			float32 getValue(){
				return value_;
			}
		};
	}
}



#endif