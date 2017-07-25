#include "thread.hpp"
#include "frame.hpp"


using namespace jvm::rtda::stack;
using namespace jvm::rtda::heap;

Frame::Frame(Thread* thread, int op_size, int loc_var_size){
	operand_stack_ = new OperandStack(op_size);
	local_vars_ = new LocalVars(loc_var_size);
	thread_ = thread;
	next_pc_ = 0;
}


OperandStack* Frame::GetOperandStack(){
	return operand_stack_;
}

LocalVars* Frame::GetLocalVars(){
	return local_vars_;
}

Thread* Frame::GetThread(){
	return thread_;
}

Method* Frame::getMethod(){
	return method_;
}

int Frame::NextPc(){
	return next_pc_;
}

void Frame::SetNextPC(int pc){
	next_pc_ = pc;
}


Frame::~Frame(){
	if (operand_stack_){
		delete operand_stack_;
	}

	if (local_vars_){
		delete local_vars_;
	}
}

//ClaseMethod* Frame::Method(){
//	return method_;
//}

