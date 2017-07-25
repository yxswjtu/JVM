#ifndef __INTERPRET__HPP_
#define __INTERPRET__HPP_


#include "../rtda/stack/thread.hpp"
#include "../classfile/fileds/member_info.hpp"

namespace jvm{
	namespace instruction{
		class Interpret{
		private:
			jvm::classfile::MemberInfo* method_;
			void __loop(jvm::rtda::stack::Thread* thread);
		public:
			Interpret(jvm::classfile::MemberInfo* method);
			void Run();
		};
	}
}




#endif