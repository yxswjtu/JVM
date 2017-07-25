#ifndef __OR_HPP_
#define __OR_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class IOR :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val1 = frame->GetOperandStack()->PopInt();
				int32 val2 = frame->GetOperandStack()->PopInt();

				frame->GetOperandStack()->Push(val1 | val2);
			}
		};

		class LOR :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val1 = frame->GetOperandStack()->PopLong();
				int64 val2 = frame->GetOperandStack()->PopLong();

				frame->GetOperandStack()->Push(val1 | val2);
			}
		};
	}
}



#endif