#ifndef __LLOAD_HPP_
#define __LLOAD_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class LLOAD :public Index8Instruction{
		public:
			void Execute(Frame* frame){
				Common::LLoad(frame, getIndex());
			}
		};


		class LLOAD_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LLoad(frame, 0);
			}
		};

		class LLOAD_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LLoad(frame, 1);
			}
		};

		class LLOAD_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LLoad(frame, 2);
			}
		};

		class LLOAD_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LLoad(frame, 3);
			}
		};
	}
}

#endif