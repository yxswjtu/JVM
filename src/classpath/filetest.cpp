#include "class_file.hpp"
#include <iostream>
#include <bitset> 
using namespace std;

int main(int argc, char* argv[]){
	ClassFile ad(std::string("F:\\vsproject\\jvm\\jvm\\jvm\\classpath\\Object.class"));

	ad.ReadClass();
	char* data = ad.GetFileData();

	for (int i = 0; i < ad.GetFileSize(); i++){
		//std::cout << hex << (unsigned int)(unsigned char)data[i] << " ";
		std::cout << (unsigned int)data[i] << " ";
	}

	return 0;
}