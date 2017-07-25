#ifndef __OPERAND_STACK_HPP_
#define __OPERAND_STACK_HPP_

#include "slot.hpp"

namespace jvm{
	namespace rtda{
		namespace stack{			
			class OperandStack{
			private:
				jvm::rtda::heap::Slot* slots_;
				int32 top_;
			public:
				OperandStack(int32 size);
				~OperandStack();

				void Push(int32 val);
				void Push(float32 val);
				void Push(int64 val);
				void Push(float64 val);
				void Push(jvm::rtda::heap::Object* ref);
				void Push(jvm::rtda::heap::slot st);

				int32 PopInt();
				float32 PopFloat();
				int64 PopLong();
				float64 PopDouble();
				jvm::rtda::heap::slot PopSlot();
				jvm::rtda::heap::Object* PopRef();
			};
		}
	}
}



#endif