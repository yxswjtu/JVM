#ifndef __MUL_HPP_
#define __MUL_HPP_


#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class DMUL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val1 = frame->GetOperandStack()->PopDouble();
				float64 val2 = frame->GetOperandStack()->PopDouble();

				frame->GetOperandStack()->Push(val1 * val2);
			}
		};

		class FMUL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val1 = frame->GetOperandStack()->PopFloat();
				float32 val2 = frame->GetOperandStack()->PopFloat();

				frame->GetOperandStack()->Push(val1 * val2);
			}
		};

		class IMUL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val1 = frame->GetOperandStack()->PopInt();
				int32 val2 = frame->GetOperandStack()->PopInt();

				frame->GetOperandStack()->Push(val1 * val2);
			}
		};

		class LMUL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val1 = frame->GetOperandStack()->PopLong();
				int64 val2 = frame->GetOperandStack()->PopLong();

				frame->GetOperandStack()->Push(val1 * val2);
			}
		};
	}
}




#endif