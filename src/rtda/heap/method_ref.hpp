#ifndef __METHOD_REF_HPP_
#define __METHOD_REF_HPP_

#include "member_ref.hpp"
#include "method.hpp"
#include "../../classfile/constant_pool/constant_methodref_info.hpp"

namespace jvm{
	namespace rtda{
		namespace heap{
			class MethodRef :public MemberRef{
			private:
				Method*  method_;
			private:
				void __resolve_method_ref();
			public:				
				MethodRef(ConstantPool*cp, jvm::classfile::ConstantMethodrefInfo* info);
				Method* getMethod();
				Method* ResolvedMethod();
			};
		}
	}
}


#endif