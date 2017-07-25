#ifndef __FLOAD_HPP_
#define __FLOAD_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class FLOAD :public Index8Instruction{
		public:
			void Execute(Frame* frame){
				Common::FLoad(frame, getIndex());
			}
		};


		class FLOAD_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FLoad(frame, 0);
			}
		};

		class FLOAD_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FLoad(frame, 1);
			}
		};

		class FLOAD_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FLoad(frame, 2);
			}
		};

		class FLOAD_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FLoad(frame, 3);
			}
		};
	}
}


#endif