#ifndef __IF_ACMP_HPP_
#define __IF_ACMP_HPP_


#include "../base/branch_instruction.hpp"
#include "../../rtda/stack/thread.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class IF_ACMPEQ :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::Object* v2 = frame->GetOperandStack()->PopRef();
				jvm::rtda::heap::Object* v1 = frame->GetOperandStack()->PopRef();

				if (v2 == v1){
					Common::Branch(frame, this->getOffset());
				}
			}
		};


		class IF_ACMPNE :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::Object* v2 = frame->GetOperandStack()->PopRef();
				jvm::rtda::heap::Object* v1 = frame->GetOperandStack()->PopRef();

				if (v2 != v1){
					Common::Branch(frame, this->getOffset());
				}
			}
		};
	}
}

#endif