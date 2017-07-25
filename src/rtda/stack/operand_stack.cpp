#include "operand_stack.hpp"
#include "../heap/object.hpp"

using namespace jvm::rtda::stack;
using namespace jvm::rtda::heap;

OperandStack::~OperandStack(){
	delete slots_;
}

OperandStack::OperandStack(int32 size):top_(0){
	slots_ = new Slot(size);
}

void OperandStack::Push(int32 val){	
	slots_->SetInt(top_, val);
	top_++;
}

int  OperandStack::PopInt(){
	top_--;
	return slots_->GetInt(top_);	
}

void OperandStack::Push(float32 val){
	slots_->SetFloat(top_,val);	
	top_++;
}

float OperandStack::PopFloat(){
	top_--;
	return slots_->GetFloat(top_);
}

void OperandStack::Push(int64 val){
	slots_->SetLong(top_,val);
	top_ += 2;
}

int64 OperandStack::PopLong(){
	top_ -= 2;
	return slots_->GetLong(top_);
}

void OperandStack::Push(float64 val){	
	slots_->SetDouble(top_,val);
	top_ += 2;
}

float64 OperandStack::PopDouble(){
	top_ -= 2;
	return slots_->GetDouble(top_);
}

void OperandStack::Push(Object* ref){
	slots_->SetRef(top_, ref);
	top_++;
}

slot OperandStack::PopSlot(){
	top_--;
	return slots_->GetSlot(top_);
}

void OperandStack::Push(slot st){
	slots_->SetSlot(top_,st);
	top_++;
}


Object* OperandStack::PopRef(){
	top_--;
	//存在泄漏，暂时不管
	return slots_->GetRef(top_);
}