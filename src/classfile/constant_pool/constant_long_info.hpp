#ifndef __CONSTANT_LONG_HPP_
#define __CONSTANT_LONG_HPP_

#include "constant_info.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace classfile{
		class ConstantLongInfo :public ConstantInfo{
		private:
			int64 value_;
		public:
			void readInfo(jvm::util::ClassReader* reader){
				value_ = (int64)reader->readUint64();
			}

			int64 getValue(){
				return value_;
			}
		};
	}
}



#endif