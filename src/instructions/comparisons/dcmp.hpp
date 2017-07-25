#ifndef __DCMP_HPP_
#define __DCMP_HPP_

#include "../../util/common.hpp"
#include "../base/no_operands.hpp"

namespace jvm{
	namespace instruction{
		class DCMPG :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DCmp(frame, true);
			}
		};

		class DCMPL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::DCmp(frame, false);
			}
		};
	}
}


#endif