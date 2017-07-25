#ifndef __ALOAD_HPP_
#define __ALOAD_HPP_

#include "../base/index_8_instruction.hpp"
#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class ALOAD :public Index8Instruction{
		public:
			void Execute(Frame* frame){
				Common::ALoad(frame, getIndex());
			}
		};


		class ALOAD_0 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ALoad(frame, 0);
			}
		};

		class ALOAD_1 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ALoad(frame, 1);
			}
		};

		class ALOAD_2 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ALoad(frame, 2);
			}
		};

		class ALOAD_3 :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::ALoad(frame, 3);
			}
		};
	}
}



#endif