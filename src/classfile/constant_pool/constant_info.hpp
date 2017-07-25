#ifndef __CONSTANT_INFO_HPP_
#define __CONSTANT_INFO_HPP_

#include "../../common/global.hpp"
#include "../../util/reader.hpp"


namespace jvm{
	namespace classfile{
		enum CONSTANT_INFO_TAG{
			CONSTANT_Class = 7,
			CONSTANT_Fieldref = 9,
			CONSTANT_Methodref = 10,
			CONSTANT_InterfaceMethodref = 11,
			CONSTANT_String = 8,
			CONSTANT_Integer = 3,
			CONSTANT_Float = 4,
			CONSTANT_Long = 5,
			CONSTANT_Double = 6,
			CONSTANT_NameAndType = 12,
			CONSTANT_Utf8 = 1,
			CONSTANT_MethodHandle = 15,
			CONSTANT_MethodType = 16,
			CONSTANT_InvokeDynamic = 18
		};

		class ConstantInfo{
			private:
				uint8 tag_;
			public:
				void  setTag(uint8 tag){ tag_ = tag; }
				uint8 getTag(){ return tag_; }
				virtual void readInfo(jvm::util::ClassReader* reader){}
		};	
	}
}


#endif