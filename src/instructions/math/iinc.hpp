#ifndef __IINC_HPP_
#define __IINC_HPP_

#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class IINC :public NoOperandsInstruction{
		private:
			uint32 index_;
			int32  const_;
		public:

			void FetchOperands(BytecodeReader* reader){
				index_ = reader->ReadUint8();
				const_ = reader->ReadInt8();
			}

			void Execute(Frame* frame){
				int32 val = frame->GetLocalVars()->GetInt(index_);
				frame->GetLocalVars()->SetInt(index_, val + const_);
			}

			uint32 getIndex(){
				return index_;
			}

			int32 getConst(){
				return const_;
			}

			void setIndex(uint32 index){

			}

			void setConst(int32  const){

			}
		};
	}
}

#endif