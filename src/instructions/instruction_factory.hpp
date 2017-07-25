#ifndef __INSTRUCTION_FACTORY_HPP_
#define __INSTRUCTION_FACTORY_HPP_

#include "../instructions/base/instruction.hpp"

namespace jvm{
	namespace instruction{
		class InstructionFactory{
		public:
			static Instruction* NewInstruction(uint8 opcode);
		};

	}
}



#endif