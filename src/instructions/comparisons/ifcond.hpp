#ifndef __IFCOND_HPP_
#define __IFCOND_HPP_

#include "../base/branch_instruction.hpp"
#include "../../rtda/stack/thread.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class IFEQ :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				if (val == 0){
					Common::Branch(frame, this->getOffset());
				}
			}
		};

		class IFNE :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				if (val != 0){
					Common::Branch(frame, this->getOffset());
				}
			}
		};

		class IFLT :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				if (val < 0){
					Common::Branch(frame, this->getOffset());
				}
			}
		};

		class IFLE :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				if (val <= 0){
					Common::Branch(frame, this->getOffset());
				}
			}
		};

		class IFGT :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				if (val > 0){
					Common::Branch(frame, this->getOffset());
				}
			}
		};

		class IFGE :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 val = frame->GetOperandStack()->PopInt();

				if (val >= 0){
					Common::Branch(frame, this->getOffset());
				}
			}
		};
	}
}




#endif