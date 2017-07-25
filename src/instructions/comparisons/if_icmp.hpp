#ifndef __IF_ICMP_HPP_
#define __IF_ICMP_HPP_

#include "../base/branch_instruction.hpp"
#include "../../rtda/stack/thread.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class IF_ICMPEQ :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 v2 = frame->GetOperandStack()->PopInt();
				int32 v1 = frame->GetOperandStack()->PopInt();

				if (v2 == v1){
					Common::Branch(frame, this->getOffset());
				}
			}
		};


		class IF_ICMPNE :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 v2 = frame->GetOperandStack()->PopInt();
				int32 v1 = frame->GetOperandStack()->PopInt();

				if (v2 != v1){
					Common::Branch(frame, this->getOffset());
				}
			}
		};

		class IF_ICMPLT :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 v2 = frame->GetOperandStack()->PopInt();
				int32 v1 = frame->GetOperandStack()->PopInt();

				if (v1 < v2){
					Common::Branch(frame, this->getOffset());
				}
			}
		};


		class IF_ICMPLE :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 v2 = frame->GetOperandStack()->PopInt();
				int32 v1 = frame->GetOperandStack()->PopInt();

				if (v1 <= v2){
					Common::Branch(frame, this->getOffset());
				}
			}
		};


		class IF_ICMPGT :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 v2 = frame->GetOperandStack()->PopInt();
				int32 v1 = frame->GetOperandStack()->PopInt();

				if (v1 > v2){
					Common::Branch(frame, this->getOffset());
				}
			}
		};


		class IF_ICMPGE :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				int32 v2 = frame->GetOperandStack()->PopInt();
				int32 v1 = frame->GetOperandStack()->PopInt();

				if (v1 >= v2){
					Common::Branch(frame, this->getOffset());
				}
			}
		};

	}
}


#endif