#ifndef __POP_HPP_
#define __POP_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class POP :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				frame->GetOperandStack()->PopSlot();
			}
		};

		class POP2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				frame->GetOperandStack()->PopSlot();
				frame->GetOperandStack()->PopSlot();
			}
		};
	}
}
#endif