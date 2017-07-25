#ifndef __FRAME_HPP_
#define __FRAME_HPP_

#include "local_vars.hpp"
#include "operand_stack.hpp"
#include "../heap/method.hpp"

namespace jvm{
	namespace rtda{
		namespace stack{
			class Thread;
			
			class Frame{
			private:
				OperandStack* operand_stack_;
				LocalVars   * local_vars_;
				Thread*       thread_;
				int           next_pc_;
				jvm::rtda::heap::Method*  method_;
			public:
				OperandStack* GetOperandStack();
				LocalVars* GetLocalVars();
				Thread* GetThread();
				jvm::rtda::heap::Method* getMethod();
				int NextPc();
				void SetNextPC(int pc);
				Frame(Thread* thread, int op_size, int loc_var_size);
				~Frame();
			};
		}
	}
}


#endif