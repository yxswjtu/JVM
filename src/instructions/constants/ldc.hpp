#ifndef __LDC_HPP_
#define __LDC_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/index_16_instruction.hpp"

namespace jvm{
	namespace instruction{
		class LDC :public Index8Instruction{
		public:
			void Execute(Frame* frame);
		};

		class LDC_W :public Index8Instruction{
		public:
			void Execute(Frame* frame);
		};

		class LDC2_W :public Index8Instruction{
		public:
			void Execute(Frame* frame);
		};
	}
}


#endif