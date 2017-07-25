#ifndef __SWAP_HPP_
#define __SWAP_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class SWAP :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::slot st1 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st2 = frame->GetOperandStack()->PopSlot();

				frame->GetOperandStack()->Push(st1);
				frame->GetOperandStack()->Push(st2);
			}
		};
	}
}

#endif