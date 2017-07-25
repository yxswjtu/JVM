#ifndef __INDEX_16_INSTRUCTION_HPP_
#define __INDEX_16_INSTRUCTION_HPP_

#include "instruction.hpp"
#include "../../util/reader.hpp"

namespace jvm{
	namespace instruction{
		class Index16Instruction :public Instruction{
		private:
			uint32 index_;
		public:

			void FetchOperands(BytecodeReader* reader){
				index_ = reader->ReadUint16();
			}

			uint32 getIndex(){
				return index_;
			}
		};
	}
}



#endif