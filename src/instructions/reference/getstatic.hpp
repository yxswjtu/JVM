#ifndef __GET_STATIC_HPP_
#define __GET_STATIC_HPP_

#include "../base/index_16_instruction.hpp"

namespace jvm{
	namespace instruction{
		class GET_STATIC :public Index16Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}

#endif