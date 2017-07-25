#ifndef __THREAD_HPP_
#define __THREAD_HPP_

#include "stack.hpp"

namespace jvm{
	namespace rtda{
		namespace stack{
			class Thread{
			private:
				int pc_;
				Stack* stack_;
			public:
				Thread(int size);
				~Thread();

				int PC(){ return pc_; }
				void SetPC(int pc) { pc_ = pc; }
				void PushFrame(Frame* frame);
				Frame* PopFrame();
				Frame* CurrentFrame();
			};
		}
	}
}



#endif