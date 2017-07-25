#ifndef __ASTORE_HPP_
#define __ASTORE_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class ASTORE :public Index8Instruction{
			void Execute(Frame* frame){
				Common::AStore(frame, getIndex());
			}
		};


		class ASTORE_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::AStore(frame, 0);
			}
		};

		class ASTORE_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::AStore(frame, 1);
			}
		};

		class ASTORE_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::AStore(frame, 2);
			}
		};

		class ASTORE_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::AStore(frame, 3);
			}
		};
	}
}



#endif