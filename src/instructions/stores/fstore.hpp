#ifndef __FSTORE_HPP_
#define __FSTORE_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class FSTORE :public Index8Instruction{
		public:
			void Execute(Frame* frame){
				Common::FStore(frame, getIndex());
			}
		};


		class FSTORE_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FStore(frame, 0);
			}
		};

		class FSTORE_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FStore(frame, 1);
			}
		};

		class FSTORE_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FStore(frame, 2);
			}
		};

		class FSTORE_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FStore(frame, 3);
			}
		};
	}
}

#endif