#ifndef __COMMON_HPP_
#define __COMMON_HPP_

#include "../rtda/stack/frame.hpp"

class Common{
public:
	static void Branch(jvm::rtda::stack::Frame* frame, int32 offset);
	static void ALoad(jvm::rtda::stack::Frame* frame, int32 index);
	static void DLoad(jvm::rtda::stack::Frame* frame, int32 index);
	static void FLoad(jvm::rtda::stack::Frame* frame, int32 index);
	static void ILoad(jvm::rtda::stack::Frame* frame, int32 index);
	static void LLoad(jvm::rtda::stack::Frame* frame, int32 index);
	static void AStore(jvm::rtda::stack::Frame* frame, int32 index);
	static void DStore(jvm::rtda::stack::Frame* frame, int32 index);
	static void FStore(jvm::rtda::stack::Frame* frame, int32 index);
	static void IStore(jvm::rtda::stack::Frame* frame, int32 index);
	static void LStore(jvm::rtda::stack::Frame* frame, int32 index);
	static void DCmp(jvm::rtda::stack::Frame* frame, bool flag);
	static void FCmp(jvm::rtda::stack::Frame* frame, bool flag);
};

#endif