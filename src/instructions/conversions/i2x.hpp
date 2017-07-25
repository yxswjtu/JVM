#ifndef __I2X_HPP_
#define __I2X_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class I2B :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();
				int8 tmp = val;

				frame->GetOperandStack()->Push((int32)tmp);
			}
		};

		class I2C :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();
				uint16 tmp = val;

				frame->GetOperandStack()->Push((int32)tmp);
			}
		};

		class I2S :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();
				int16 tmp = val;

				frame->GetOperandStack()->Push((int32)tmp);
			}
		};

		class I2L :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				frame->GetOperandStack()->Push((int64)val);
			}
		};

		class I2F :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				frame->GetOperandStack()->Push((float32)val);
			}
		};

		class I2D :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				frame->GetOperandStack()->Push((float64)val);
			}
		};
	}
}



#endif