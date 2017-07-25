#ifndef __CHECK_CAST_HPP_
#define __CHECK_CAST_HPP_

#include "../base/index_16_instruction.hpp"

namespace jvm{
	namespace instruction{
		class CHECK_CAST :public Index16Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}


#endif