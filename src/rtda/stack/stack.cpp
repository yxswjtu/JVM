#include "stack.hpp"
#include <iostream>

using namespace jvm::rtda::stack;

void Stack::push(Frame* frame){
	if ((int)frames_.size() >= max_size_){
		std::cout << "stack overflow" << std::endl;
	}
	frames_.push(frame);
}

Frame* Stack::pop(){
	Frame* tmp = NULL;

	if (true == frames_.empty()){
		std::cout << "stack is empty" << std::endl;
		return NULL;
	}
	else{
		tmp = frames_.top();
		frames_.pop();
	}
	return tmp;
}

Frame* Stack::top(){
	Frame* tmp = NULL;

	if (true == frames_.empty()){
		std::cout << "stack is empty" << std::endl;
		return NULL;
	}
	else{
		tmp = frames_.top();
	}
	return tmp;
}