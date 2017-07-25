#ifndef __L2X_HPP_
#define __L2X_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class L2D :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val = frame->GetOperandStack()->PopLong();
				frame->GetOperandStack()->Push((float64)val);
			}
		};

		class L2F :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val = frame->GetOperandStack()->PopLong();
				frame->GetOperandStack()->Push((float32)val);
			}
		};

		class L2I :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val = frame->GetOperandStack()->PopLong();
				frame->GetOperandStack()->Push((int32)val);
			}
		};
	}
}


#endif