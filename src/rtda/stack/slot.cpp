#include "slot.hpp"
#include "../heap/object.hpp"
#include <iostream>

using namespace jvm::rtda::heap;

Slot::Slot(int32 size){
	local_vars_.resize(size);
	for (int32 i = 0; i < size; i++){
		local_vars_[i].num = 0;
	}
}

void Slot::SetInt(int index, int32 val){
	slot tmp;

	tmp.num = val;
	local_vars_[index] = tmp;
	std::cout << "set local var->index:" << index << " val:" << local_vars_[index].num<< std::endl;
}

int32  Slot::GetInt(int32 index){
	return local_vars_[index].num;
}

void  Slot::SetFloat(int32 index, float32 val){
	slot tmp;

	tmp.fnum = val;
	local_vars_[index] = tmp;
}

float32 Slot::GetFloat(int32 index){
	return local_vars_[index].fnum;
}

void  Slot::SetLong(int32 index, int64 val){
	local_vars_[index].num = (int32)val;
	local_vars_[index + 1].num = val >> 32;
}

int64  Slot::GetLong(int32 index){
	int64 low = local_vars_[index].num;
	int64 high = local_vars_[index + 1].num;
	return (high << 32) | low;
}

void  Slot::SetDouble(int32 index, float64 val){
	Long temp;

	temp.dnum = val;
	SetLong(index, temp.lnum);
}

float64 Slot::GetDouble(int32 index){
	Long temp;

	temp.lnum = GetLong(index);
	return temp.dnum;
}

void Slot::SetRef(int32 index,Object* ref){
	local_vars_[index].ref = ref;
}

Object* Slot::GetRef(int32 index){
	return local_vars_[index].ref;
}

void Slot::SetSlot(int32 index, slot lot){
	local_vars_[index] = lot;
}

slot Slot::GetSlot(int32 index){
	return local_vars_[index];
}