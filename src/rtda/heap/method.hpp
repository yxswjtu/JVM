#ifndef __CLASE_METHOD_HPP_
#define __CLASE_METHOD_HPP_

#include "clase_member.hpp"

namespace jvm{
	namespace rtda{
		namespace heap{
			class Method :public ClaseMember{
			private:
				uint32 max_stack_;
				uint32 max_locals_;
				uint32 code_length_;
				uint8* code_;
			public:
				void copyAtrributes(jvm::classfile::MemberInfo* info);
			public:
				~Method(); 
				Method();
				bool  IsSynchronized();
				bool IsBridge();
				bool IsVarargs();
				bool IsNative();
				bool IsAbstract();
				bool IsStrict();

				//getter
				uint32 getMaxStack();
				uint32 getMaxLocals();
				uint8* getCode();

				std::vector<Method*> newFields(Clase* clase, std::vector<jvm::classfile::MemberInfo*>& cmethods);
				
			};
		}
	}
}



#endif