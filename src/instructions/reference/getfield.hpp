#ifndef __GET_FIELD_HPP_
#define __GET_FIELD_HPP_

#include "../base/index_16_instruction.hpp"

namespace jvm{
	namespace instruction{
		class GET_FIELD :public Index16Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}


#endif