#ifndef __TABLE_SWITCH_HPP_
#define __TABLE_SWITCH_HPP_

#include "../base/branch_instruction.hpp"
#include "../../util/common.hpp"
#include <vector>

namespace jvm{
	namespace instruction{
		class TABLE_SWITCH :public BranchInstruction{
		public:
			int32 default_offset_;
			int32 low_;
			int32 high_;
			std::vector<int32> jump_offsets_;

			void FetchOperands(BytecodeReader* reader){
				reader->SkipPadding();
				default_offset_ = reader->ReadInt32();
				low_ = reader->ReadInt32();
				high_ = reader->ReadInt32();
				jump_offsets_ = reader->ReadInt32s(high_ - low_ + 1);
			}

			void Execute(Frame* frame){
				int32 index = frame->GetOperandStack()->PopInt();

				int32 offset = default_offset_;
				if ((index <= high_) && (index >= low_)){
					offset = jump_offsets_[index - low_];
				}

				Common::Branch(frame, offset);
			}
		};
	}
}



#endif