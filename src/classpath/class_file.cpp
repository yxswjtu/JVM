#include "class_file.hpp"


ClassFile::ClassFile(std::string& path):IFile(path){

}

ClassFile::~ClassFile(){
	if (fs_.is_open()){
		fs_.close();
	}
}

bool ClassFile::ReadClass(){

	if (false == path_.empty()){
		fs_.open(path_, std::ios::in | std::ios::binary | std::ios::ate);
		if (false == fs_.is_open()){
			return false;
		}

		long size = fs_.tellg();
		size_ = size;
		fs_.seekg(0, std::ios::beg);

		data_ = new char[size];
		if (NULL == data_){
			return false;
		}

		fs_.read(data_, size);

	}

	return true;
}


