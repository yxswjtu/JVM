#ifndef __BRANCH_INSTRUCTION_HPP_
#define __BRANCH_INSTRUCTION_HPP_

#include "instruction.hpp"

namespace jvm{
	namespace instruction{
		class BranchInstruction :public Instruction{
		private:
			int16 offset_;
		public:

			void FetchOperands(BytecodeReader* reader){
				offset_ = reader->ReadInt16();
			}

			int16 getOffset(){
				return offset_;
			}
		};

	}
}



#endif