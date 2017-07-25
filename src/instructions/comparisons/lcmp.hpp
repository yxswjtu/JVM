#ifndef __LCMP_HPP_
#define __LCMP_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class LCMP :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64  v2 = frame->GetOperandStack()->PopLong();
				int64  v1 = frame->GetOperandStack()->PopLong();

				if (v1 > v2){
					frame->GetOperandStack()->Push(1);
				}
				else if (v1 == v2){
					frame->GetOperandStack()->Push(0);
				}
				else{
					frame->GetOperandStack()->Push(-1);
				}

			}
		};
	}
}



#endif