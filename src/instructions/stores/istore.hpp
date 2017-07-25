#ifndef __ISTORE_HPP_
#define __ISTORE_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class ISTORE :public Index8Instruction{
			void Execute(Frame* frame){
				Common::IStore(frame, getIndex());
			}
		};


		class ISTORE_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::IStore(frame, 0);
			}
		};

		class ISTORE_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::IStore(frame, 1);
			}
		};

		class ISTORE_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::IStore(frame, 2);
			}
		};

		class ISTORE_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::IStore(frame, 3);
			}
		};
	}
}




#endif