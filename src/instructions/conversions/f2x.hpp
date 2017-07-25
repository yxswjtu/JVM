#ifndef __F2X_HPP_
#define __F2X_HPP_


#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class F2D :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val = frame->GetOperandStack()->PopFloat();

				frame->GetOperandStack()->Push((float64)val);
			}
		};

		class F2I :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val = frame->GetOperandStack()->PopFloat();

				frame->GetOperandStack()->Push((int32)val);
			}
		};

		class F2L :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val = frame->GetOperandStack()->PopFloat();

				frame->GetOperandStack()->Push((int64)val);
			}
		};

	}
}


#endif