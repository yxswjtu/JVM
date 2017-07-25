#ifndef __NEW_HPP_
#define __NEW_HPP_

#include "../base/index_16_instruction.hpp"

namespace jvm{
	namespace instruction{
		class New :public Index16Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}


#endif