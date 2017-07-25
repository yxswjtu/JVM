#ifndef __REM_HPP_
#define __REM_HPP_

#include "../base/no_operands.hpp"
#include <math.h>
#include <iostream>

namespace jvm{
	namespace instruction{
		class DREM :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float64 val2 = frame->GetOperandStack()->PopDouble();
				float64 val1 = frame->GetOperandStack()->PopDouble();

				frame->GetOperandStack()->Push(fmod(val1, val2));
			}
		};

		class FREM :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				float32 val2 = frame->GetOperandStack()->PopFloat();
				float32 val1 = frame->GetOperandStack()->PopFloat();

				frame->GetOperandStack()->Push(fmodf(val1, val2));
			}
		};

		class IREM :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int32 val1 = frame->GetOperandStack()->PopInt();

				if (val2 == 0){
					std::cout << "java.lang.ArithmeticException: / by zero" << std::endl;
					return;
				}

				frame->GetOperandStack()->Push(val1 % val2);
			}
		};

		class LREM :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int64 val2 = frame->GetOperandStack()->PopLong();
				int64 val1 = frame->GetOperandStack()->PopLong();

				if (val2 == 0){
					std::cout << "java.lang.ArithmeticException: / by zero" << std::endl;
					return;
				}

				frame->GetOperandStack()->Push(val1 % val2);
			}
		};
	}
}


#endif