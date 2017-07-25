#ifndef __PUTSTATIC_HPP_
#define __PUTSTATIC_HPP_

#include "../base/index_16_instruction.hpp"

namespace jvm{
	namespace instruction{
		class PUT_STATIC :public Index16Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}



#endif