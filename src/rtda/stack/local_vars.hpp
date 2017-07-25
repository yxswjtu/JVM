#ifndef __LOCAL_VARS_HPP_
#define __LOCAL_VARS_HPP_

#include "slot.hpp"

namespace jvm{
	namespace rtda{
		namespace stack{
			class LocalVars :public jvm::rtda::heap::Slot{

			public:
				//in bytes
				LocalVars(int size) :Slot(size){}
			};
		}
	}
}


#endif