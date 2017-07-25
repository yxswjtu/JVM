#ifndef __INSTANCE_OF_HPP_
#define __INSTANCE_OF_HPP_


#include "../base/index_16_instruction.hpp"

namespace jvm{
	namespace instruction{
		class INSTANCE_OF :public Index16Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}


#endif