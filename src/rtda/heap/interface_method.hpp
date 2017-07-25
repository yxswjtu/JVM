#ifndef __INTRFACE_METHOD_HPP_
#define __INTRFACE_METHOD_HPP_

#include "member_ref.hpp"
#include "method.hpp"
#include "../../classfile/constant_pool/constant_interfacemethodref_info.hpp"


namespace jvm{
	namespace rtda{
		namespace heap{
			class InterfaceMethodRef :public MemberRef{
			private:
				Method*  method_;
			private:
				void __resolve_interface_method_ref();
			public:				
				InterfaceMethodRef(ConstantPool*cp, jvm::classfile::ConstantInterfaceMethodrefInfo* info);
				Method* getMethod();
				Method* ResolvedInterfaceMethod();
			};
		}
	}
}




#endif