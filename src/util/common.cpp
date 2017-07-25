#include "common.hpp"
#include "../rtda/stack/thread.hpp"

using namespace jvm::rtda::stack;
using namespace jvm::rtda::heap;

void Common::Branch(Frame* frame, int32 offset){
	int32 pc = frame->GetThread()->PC();
	frame->SetNextPC(pc + offset);
}

void Common::ALoad(Frame* frame, int32 index){
	Object* ref = frame->GetLocalVars()->GetRef(index);
	frame->GetOperandStack()->Push(ref);
}

void Common::DLoad(Frame* frame, int32 index){
	float64 val = frame->GetLocalVars()->GetDouble(index);
	frame->GetOperandStack()->Push(val);
}

void Common::FLoad(Frame* frame, int32 index){
	float32 val = frame->GetLocalVars()->GetFloat(index);
	frame->GetOperandStack()->Push(val);
}

void Common::ILoad(Frame* frame, int32 index){
	int32 val = frame->GetLocalVars()->GetInt(index);
	frame->GetOperandStack()->Push(val);
}

void Common::LLoad(Frame* frame, int32 index){
	int64 val = frame->GetLocalVars()->GetLong(index);
	frame->GetOperandStack()->Push(val);
}

void Common::AStore(Frame* frame, int32 index){
	Object* val = frame->GetOperandStack()->PopRef();
	frame->GetLocalVars()->SetRef(index, val);
}

void Common::DStore(Frame* frame, int32 index){
	float64 val = frame->GetOperandStack()->PopDouble();
	frame->GetLocalVars()->SetDouble(index, val);
}

void Common::FStore(Frame* frame, int32 index){
	float32 val = frame->GetOperandStack()->PopFloat();
	frame->GetLocalVars()->SetFloat(index, val);
}

void Common::IStore(Frame* frame, int32 index){
	int32 val = frame->GetOperandStack()->PopInt();
	frame->GetLocalVars()->SetInt(index, val);
}

void Common::LStore(Frame* frame, int32 index){
	int64 val = frame->GetOperandStack()->PopLong();
	frame->GetLocalVars()->SetLong(index, val);
}

void Common::DCmp(Frame* frame, bool flag){
	float64 v2 = frame->GetOperandStack()->PopDouble();
	float64 v1 = frame->GetOperandStack()->PopDouble();

	if (v1 > v2){
		frame->GetOperandStack()->Push(1);
	}
	else if (v1 == v2){
		frame->GetOperandStack()->Push(0);
	}
	else if (v1 < v2){
		frame->GetOperandStack()->Push(-1);
	}
	else if (flag){
		frame->GetOperandStack()->Push(1);
	}
	else{
		frame->GetOperandStack()->Push(-1);
	}
}

void Common::FCmp(Frame* frame, bool flag){
	float32 v2 = frame->GetOperandStack()->PopFloat();
	float32 v1 = frame->GetOperandStack()->PopFloat();

	if (v1 > v2){
		frame->GetOperandStack()->Push(1);
	}
	else if (v1 == v2){
		frame->GetOperandStack()->Push(0);
	}
	else if (v1 < v2){
		frame->GetOperandStack()->Push(-1);
	}
	else if (flag){
		frame->GetOperandStack()->Push(1);
	}
	else{
		frame->GetOperandStack()->Push(-1);
	}
}