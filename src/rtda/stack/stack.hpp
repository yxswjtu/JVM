#ifndef __STACK_HPP_
#define __STACK_HPP_

#include "frame.hpp"
#include <stack>

namespace jvm{
	namespace rtda{
		namespace stack{
			class Stack{
			private:
				int max_size_;
				std::stack<Frame*> frames_;
			public:
				Stack(int size) :max_size_(size){}

				void push(Frame* frame);
				Frame* pop();
				Frame* top();
				int max_size() { return max_size_; }
			};
		}
	}
}




#endif