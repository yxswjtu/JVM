#ifndef __ADD_HPP_
#define __ADD_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class DADD :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val1 = frame->GetOperandStack()->PopDouble();
				float64 val2 = frame->GetOperandStack()->PopDouble();

				frame->GetOperandStack()->Push(val1 + val2);
			}
		};

		class FADD :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val1 = frame->GetOperandStack()->PopFloat();
				float32 val2 = frame->GetOperandStack()->PopFloat();

				frame->GetOperandStack()->Push(val1 + val2);
			}
		};

		class IADD :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val1 = frame->GetOperandStack()->PopInt();
				int32 val2 = frame->GetOperandStack()->PopInt();

				frame->GetOperandStack()->Push(val1 + val2);
			}
		};

		class LADD :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val1 = frame->GetOperandStack()->PopLong();
				int64 val2 = frame->GetOperandStack()->PopLong();

				frame->GetOperandStack()->Push(val1 + val2);
			}
		};
	}
}

#endif