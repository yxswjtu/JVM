#ifndef __CLASS_FILE_HPP_
#define __CLASS_FILE_HPP_

#include "ifile.hpp"
#include <fstream>

class ClassFile :public IFile{
public:
	ClassFile(std::string& path);
	~ClassFile();
	bool ReadClass();	
private:
	std::fstream fs_;
};

#endif