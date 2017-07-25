#ifndef __SUB_HPP_
#define __SUB_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class DSUB :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val2 = frame->GetOperandStack()->PopDouble();
				float64 val1 = frame->GetOperandStack()->PopDouble();

				frame->GetOperandStack()->Push(val1 - val2);
			}
		};

		class FSUB :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val2 = frame->GetOperandStack()->PopFloat();
				float32 val1 = frame->GetOperandStack()->PopFloat();

				frame->GetOperandStack()->Push(val1 - val2);
			}
		};

		class ISUB :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int32 val1 = frame->GetOperandStack()->PopInt();

				frame->GetOperandStack()->Push(val1 - val2);
			}
		};

		class LSUB :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val2 = frame->GetOperandStack()->PopLong();
				int64 val1 = frame->GetOperandStack()->PopLong();

				frame->GetOperandStack()->Push(val1 - val2);
			}
		};
	}
}


#endif