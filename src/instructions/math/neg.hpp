#ifndef __NEG_HPP_
#define __NEG_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class DNEG :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val2 = frame->GetOperandStack()->PopDouble();
				frame->GetOperandStack()->Push(-val2);
			}
		};

		class FNEG :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val2 = frame->GetOperandStack()->PopFloat();
				frame->GetOperandStack()->Push(-val2);
			}
		};

		class INEG :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				frame->GetOperandStack()->Push(-val2);
			}
		};

		class LNEG :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val2 = frame->GetOperandStack()->PopLong();
				frame->GetOperandStack()->Push(-val2);
			}
		};
	}
}



#endif