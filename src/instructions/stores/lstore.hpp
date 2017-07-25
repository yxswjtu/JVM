#ifndef __LSTORE_HPP_
#define __LSTORE_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class LSTORE :public Index8Instruction{
		public:
			void Execute(Frame* frame){
				Common::LStore(frame, getIndex());
			}
		};


		class LSTORE_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LStore(frame, 0);
			}
		};

		class LSTORE_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LStore(frame, 1);
			}
		};

		class LSTORE_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LStore(frame, 2);
			}
		};

		class LSTORE_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::LStore(frame, 3);
			}
		};
	}
}


#endif