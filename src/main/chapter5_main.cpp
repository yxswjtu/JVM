#include "../classfile/class_file.hpp"
#include "../interpret/interpret.hpp"
#include <iostream>

using namespace jvm::classfile;
using namespace jvm::rtda::stack;
using namespace jvm::instruction;

int main(){
	ClassFile file(std::string("GaussTest.class"));
	file.Parse();

	std::vector<MemberInfo*> methods = file.getMethods();
	std::vector<MemberInfo*>::iterator it;
	MemberInfo* method = NULL;

	for (it = methods.begin(); it != methods.end(); it++){
		if ((*it)->getName() == std::string("main") && (*it)->getDescriptor() == std::string("([Ljava/lang/String;)V")){
			method = *it;
			break;
		}
	}

	if (!method){
		std::cout << "no main mehtod" << std::endl;
		return 0;
	}

	Interpret intpret(method);
	intpret.Run();


	return 0;
}