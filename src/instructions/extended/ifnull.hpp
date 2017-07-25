#ifndef __IFNULL_HPP_
#define __IFNULL_HPP_

#include "../base/branch_instruction.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class IFNULL :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::Object* ref = frame->GetOperandStack()->PopRef();

				if (NULL == ref){
					Common::Branch(frame, getOffset());
				}
			}
		};


		class IFNONNULL :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				jvm::rtda::heap::Object* ref = frame->GetOperandStack()->PopRef();

				if (NULL != ref){
					Common::Branch(frame, getOffset());
				}
			}
		};
	}
}



#endif