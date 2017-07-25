#ifndef __D2X_HPP_
#define __D2X_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class D2F :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val = frame->GetOperandStack()->PopDouble();

				frame->GetOperandStack()->Push((float32)val);
			}
		};

		class D2I :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val = frame->GetOperandStack()->PopDouble();

				frame->GetOperandStack()->Push((int32)val);
			}
		};

		class D2L :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val = frame->GetOperandStack()->PopDouble();
				frame->GetOperandStack()->Push((int64)val);
			}
		};
	}
}




#endif