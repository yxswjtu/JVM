#ifndef __FCMP_HPP_
#define __FCMP_HPP_

#include "../base/no_operands.hpp"
#include "../../util/common.hpp"

namespace jvm{
	namespace instruction{
		class FCMPG :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FCmp(frame, true);
			}
		};

		class FCMPL :public NoOperandsInstruction{
		public:
			void Execute(Frame* frame){
				Common::FCmp(frame, false);
			}
		};
	}
}



#endif