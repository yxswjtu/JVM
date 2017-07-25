#ifndef __PUT_FIELD_HPP_
#define __PUT_FIELD_HPP_

#include "../base/index_16_instruction.hpp"


namespace jvm{
	namespace instruction{
		class PUT_FIELD :public Index16Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}

#endif