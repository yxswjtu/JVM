#include "options\options.hpp"
#include "classfile\constant_integer_info.hpp"

int main(int argc, char*argv[]){
	
	Options* op = new Options();
	if (!op){
		return 0;
	}

	op->Init();

	op->Parse(argc, argv);

	op->Release();

	delete op;

	return 0;
}