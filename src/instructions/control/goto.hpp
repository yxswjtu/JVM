#ifndef __GOTO_HPP_
#define __GOTO_HPP_

#include "../base/branch_instruction.hpp"
#include "../../rtda/stack/thread.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class GOTO :public BranchInstruction{
		public:
			void Execute(Frame* frame){
				Common::Branch(frame, this->getOffset());
			}
		};
	}
}

#endif