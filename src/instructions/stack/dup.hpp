#ifndef __DUP_HPP_
#define __DUP_HPP_


#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class DUP :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::slot st = frame->GetOperandStack()->PopSlot();
				frame->GetOperandStack()->Push(st);
				frame->GetOperandStack()->Push(st);
			}
		};

		class DUP_X1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::slot st1 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st2 = frame->GetOperandStack()->PopSlot();

				frame->GetOperandStack()->Push(st1);
				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
			}
		};

		class DUP_X2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::slot st1 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st2 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st3 = frame->GetOperandStack()->PopSlot();

				frame->GetOperandStack()->Push(st1);
				frame->GetOperandStack()->Push(st3);
				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
			}
		};

		class DUP2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::slot st1 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st2 = frame->GetOperandStack()->PopSlot();

				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
			}
		};

		class DUP2_X1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::slot st1 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st2 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st3 = frame->GetOperandStack()->PopSlot();

				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
				frame->GetOperandStack()->Push(st3);
				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
			}
		};
		class DUP2_X2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::slot st1 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st2 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st3 = frame->GetOperandStack()->PopSlot();
				jvm::rtda::heap::slot st4 = frame->GetOperandStack()->PopSlot();

				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
				frame->GetOperandStack()->Push(st4);
				frame->GetOperandStack()->Push(st3);
				frame->GetOperandStack()->Push(st2);
				frame->GetOperandStack()->Push(st1);
			}
		};
	}
}


#endif