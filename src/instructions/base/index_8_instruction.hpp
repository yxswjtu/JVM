#ifndef __INDEX_8_INSTRUCTION_HPP_
#define __INDEX_8_INSTRUCTION_HPP_

#include "instruction.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace instruction{
		class Index8Instruction :public Instruction{
		private:
			uint32 index_;
		public:

			void FetchOperands(BytecodeReader* reader){
				index_ = reader->ReadUint8();
			}

			uint32 getIndex(){
				return index_;
			}

			void setIndex(uint32 index){
				index_ = index;
			}
		};
	}
}


#endif