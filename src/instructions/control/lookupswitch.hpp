#ifndef __LOOKUPSWITCH_HPP_
#define __LOOKUPSWITCH_HPP_

#include "../base/branch_instruction.hpp"
#include "../../util/common.hpp"
#include <vector>

namespace jvm{
	namespace instruction{
		class LOOKUP_SWITCH :public Instruction{
		private:
			int32 default_offset_;
			int32 npairs_;
			std::vector<int32> match_offsets_;
		public:
			void FetchOperands(BytecodeReader* reader){
				reader->SkipPadding();
				default_offset_ = reader->ReadInt32();
				npairs_ = reader->ReadInt32();
				match_offsets_ = reader->ReadInt32s(npairs_ * 2);
			}

			void Execute(Frame* frame){
				int32 key = frame->GetOperandStack()->PopInt();

				int32 offset = default_offset_;
				for (int32 i = 0; i < npairs_ * 2; i += 2){
					if (match_offsets_[i] == key){
						offset = match_offsets_[i + 1];
						Common::Branch(frame, offset);
						return;
					}
				}

				Common::Branch(frame, offset);
			}
		};
	}
}



#endif