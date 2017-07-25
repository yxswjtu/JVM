#include "../rtda/heap/clase_loader.hpp"
#include "../rtda/heap/method.hpp"
#include "../rtda/heap/clase.hpp"

#include <iostream>
using namespace jvm::rtda::heap;

int main(){
	ClaseLoader loader;
	Clase* clase =loader.LoadClass(std::string("./MyObject.class"));
	
	Method* main_method = clase->getMainMethod();
	if (NULL == main_method){
		std::cout << "get main_method" << std::endl;
	}


	return 0;
}