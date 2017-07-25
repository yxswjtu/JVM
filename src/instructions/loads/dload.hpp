#ifndef __DLOAD_HPP_
#define __DLOAD_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class DLOAD :public Index8Instruction{
			void Execute(Frame* frame){
				Common::DLoad(frame, getIndex());
			}
		};


		class DLOAD_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DLoad(frame, 0);
			}
		};

		class DLOAD_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DLoad(frame, 1);
			}
		};

		class DLOAD_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DLoad(frame, 2);
			}
		};

		class DLOAD_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DLoad(frame, 3);
			}
		};
	}
}




#endif