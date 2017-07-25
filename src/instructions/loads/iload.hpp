#ifndef __ILOAD_HPP_
#define __ILOAD_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"


namespace jvm{
	namespace instruction{
		class ILOAD :public Index8Instruction{
		public:
			void Execute(Frame* frame){
				Common::ILoad(frame, getIndex());
			}
		};


		class ILOAD_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ILoad(frame, 0);
			}
		};

		class ILOAD_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ILoad(frame, 1);
			}
		};

		class ILOAD_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ILoad(frame, 2);
			}
		};

		class ILOAD_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ILoad(frame, 3);
			}
		};

	}
}



#endif