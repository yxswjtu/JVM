#ifndef __CLASE_REF_HPP_
#define __CLASE_REF_HPP_

#include "symref.hpp"
#include "../../classfile/constant_pool/constant_class_info.hpp"

namespace jvm{
	namespace rtda{
		namespace heap{
			class ClaseRef :public SymRef{
			public:
				ClaseRef(ConstantPool* cp, jvm::classfile::ConstantClassInfo* classinfo){
					cp_ = cp;
					clase_name_ = classinfo->getName();
				}
			};
		}
	}
}



#endif