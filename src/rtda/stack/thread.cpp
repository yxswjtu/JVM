#include "thread.hpp"
#include <iostream>

using namespace jvm::rtda::stack;
//class Thread
Thread::Thread(int size):pc_(0){
	stack_ = new Stack(size);
}



Thread::~Thread(){
	if (stack_){
		delete stack_;
	}
}

void Thread::PushFrame(Frame* frame){
	stack_->push(frame);
}

Frame* Thread::PopFrame(){
	return stack_->pop();
}

Frame* Thread::CurrentFrame(){
	return stack_->top();
}