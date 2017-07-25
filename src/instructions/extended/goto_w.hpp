#ifndef __GOTO_W_HPP_
#define __GOTO_W_HPP_

#include "../base/instruction.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class GOTO_W :public Instruction{
		private:
			int32 offset_;
		public:
			void Execute(Frame* frame){
				Common::Branch(frame, offset_);
			}
			void FetchOperands(BytecodeReader* reader){
				offset_ = reader->ReadInt32();
			}

			int32 getOffset(){
				return offset_;
			}
		};
	}
}


#endif