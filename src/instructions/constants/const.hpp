#ifndef __CONST_HPP_
#define __CONST_HPP_

#include "../base/instruction.hpp"

namespace jvm{
	namespace instruction{
		class ACONST_NULL :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((jvm::rtda::heap::Object*)NULL);
			}
		};

		class DCONST_0 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((float64)0.0);
			}
		};

		class DCONST_1 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((float64)1.0);
			}
		};

		class FCONST_0 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((float32)0.0f);
			}
		};

		class FCONST_1 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((float32)1.0f);
			}
		};

		class FCONST_2 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((float32)2.0f);
			}
		};

		class ICONST_M1 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int32)-1);
			}
		};

		class ICONST_0 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int32)0);
			}
		};

		class ICONST_1 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int32)1);
			}
		};

		class ICONST_2 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int32)2);
			}
		};

		class ICONST_3 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int32)3);
			}
		};

		class ICONST_4 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int32)4);
			}
		};

		class ICONST_5 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int32)5);
			}
		};

		class LCONST_0 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int64)0);
			}
		};

		class LCONST_1 :public Instruction{
			void Execute(Frame* frame){
				frame->GetOperandStack()->Push((int64)1);
			}
		};
	}
}

#endif