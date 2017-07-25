#ifndef __DSTORE_HPP_
#define __DSTORE_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class DSTORE :public Index8Instruction{
		public:
			void Execute(Frame* frame){
				Common::DStore(frame, getIndex());
			}
		};


		class DSTORE_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DStore(frame, 0);
			}
		};

		class DSTORE_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DStore(frame, 1);
			}
		};

		class DSTORE_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DStore(frame, 2);
			}
		};

		class DSTORE_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DStore(frame, 3);
			}
		};
	}
}

#endif