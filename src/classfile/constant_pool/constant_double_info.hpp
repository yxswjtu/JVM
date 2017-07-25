#ifndef __CONSTANT_DOUBLE_HPP_
#define __CONSTANT_DOUBLE_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantDoubleInfo :public ConstantInfo{
		private:
			float64 value_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				value_ = reader->readFloat64();
			}

			float64 getValue(){
				return value_;
			}
		};
	}
}




#endif
