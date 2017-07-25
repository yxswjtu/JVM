#ifndef _IFILE_HPP_
#define _IFILE_HPP_

#include <string>

class IFile{
public:
	IFile(std::string& path) :data_(NULL), size_(0){
		path_.swap(path);
	}

	~IFile(){
		if (data_){
			delete data_;
		}
	}

	virtual bool ReadClass(){
		return true;
	};
	virtual std::string& GetFileName(){
		return path_;
	};

	char* GetFileData(){
		return data_;
	}

	long GetFileSize(){
		return size_;
	}
	
	char* data_;
	long size_;
	std::string path_;
};


#endif