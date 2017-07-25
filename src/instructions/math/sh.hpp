#ifndef __SH_HPP_
#define __SH_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class ISHL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int32 val1 = frame->GetOperandStack()->PopInt();

				uint32 c = ((uint32)val2) & 0x1f;

				frame->GetOperandStack()->Push(val1 << c);
			}
		};

		class ISHR :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int32 val1 = frame->GetOperandStack()->PopInt();

				uint32 c = ((uint32)val2) & 0x1f;

				frame->GetOperandStack()->Push(val1 >> c);
			}
		};

		class IUSHR :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int32 val1 = frame->GetOperandStack()->PopInt();

				uint32 c = (uint32)val2 & 0x1f;
				int32 res = (uint32)val1 >> c;

				frame->GetOperandStack()->Push(res);
			}
		};

		class LSHL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int64 val1 = frame->GetOperandStack()->PopLong();

				uint32 c = ((uint32)val2) & 0x3f;

				frame->GetOperandStack()->Push(val1 << c);
			}
		};

		class LSHR :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int64 val1 = frame->GetOperandStack()->PopLong();

				uint32 c = ((uint32)val2) & 0x3f;

				frame->GetOperandStack()->Push(val1 >> c);
			}
		};

		class LUSHR :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				int32 val2 = frame->GetOperandStack()->PopInt();
				int64 val1 = frame->GetOperandStack()->PopLong();

				uint32 c = ((uint32)val2) & 0x3f;
				int64 res = ((uint64)val1) >> c;

				frame->GetOperandStack()->Push(res);
			}
		};

	}
}

#endif