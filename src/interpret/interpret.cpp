#include "interpret.hpp"
#include "../rtda/stack/thread.hpp"
#include "../instructions/instruction_factory.hpp"
#include "../util/byte_code_reader.hpp"
#include <iostream>

using namespace jvm::classfile;
using namespace jvm::instruction;
using namespace jvm::rtda::stack;

Interpret::Interpret(MemberInfo* method) :method_(method){
}

void Interpret::Run(){
	CodeAttribute* code = method_->getCodeAtrribute();

	Thread thread(code->getMaxStack());
	Frame frame(&thread, code->getMaxStack(), code->getMaxLocals());

	thread.PushFrame(&frame);
	//error

	__loop(&thread);
}

void Interpret::__loop(Thread* thread){
	Frame *frame = thread->PopFrame();
	CodeAttribute* code = method_->getCodeAtrribute();
	BytecodeReader rd(code->getCode(), 0);
	

	for (;;){
		int pc = frame->NextPc();
		thread->SetPC(pc);
		rd.Reset(pc);

		uint8 opcode = rd.ReadUint8();
		Instruction* ins = InstructionFactory::NewInstruction(opcode);		
		ins->FetchOperands(&rd);
		frame->SetNextPC(rd.PC());

		std::cout << "opcode:" << (int)opcode <<" "<< "pc:" << pc << std::endl;

		ins->Execute(frame);
	}
	
}
