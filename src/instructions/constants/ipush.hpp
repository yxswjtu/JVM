#ifndef __IPUSH_HPP_
#define __IPUSH_HPP_

#include "../base/instruction.hpp"

namespace jvm{
	namespace instruction{
		class BIPUSH :public Instruction{
		private:
			int8 val_;
		public:

			void FetchOperands(BytecodeReader* reader){
				val_ = reader->ReadInt8();
			}

			void Execute(Frame* frame){
				int32 tmp = val_;
				frame->GetOperandStack()->Push(tmp);
			}
		};

		class SIPUSH :public Instruction{
		private:
			int16 val_;
		public:

			void FetchOperands(BytecodeReader* reader){
				val_ = reader->ReadInt16();
			}

			void Execute(Frame* frame){
				int32 tmp = val_;
				frame->GetOperandStack()->Push(tmp);
			}
		};
	}
}



#endif