#ifndef __INSTRUCTION_HPP_
#define __INSTRUCTION_HPP_

#include "../../common/global.hpp"
#include "../../rtda/stack/frame.hpp"
#include "../../util/byte_code_reader.hpp"

using namespace jvm::rtda::stack;

namespace jvm{
	namespace instruction{
		class Instruction{
		public:
			virtual void Execute(Frame* frame){}
			virtual void FetchOperands(BytecodeReader* reader){}
		};
	}
}

#endif