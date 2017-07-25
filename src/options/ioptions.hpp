#ifndef __IOPTIONS_HPP_
#define __IOPTIONS_HPP_

#include <string>
#include <vector>

#define INF -1

typedef struct _sOptions{
	std::string jrepath;
	std::string classpath;
	std::vector<std::string> classparmas;
}sOptions;

class IOptions{
private:
	int num_params_;
public:
	IOptions(){
		num_params_ = 0;
	}

	int GetNumParams(){
		return num_params_;
	}

	void SetNumParams(int num){
		num_params_ = num;
	}

	virtual void Execute(sOptions* const options, std::vector<std::string>& param) { }
};

class HelpOption : public IOptions{
public:
	void Execute(sOptions* const options, std::vector<std::string>&  param);
};

class ClassPath : public IOptions{
public:
	ClassPath(){
		SetNumParams(1);
	}
	void Execute(sOptions* const options, std::vector<std::string>& param);
};

class ClassPathParams : public IOptions{
public:
	ClassPathParams(){
		SetNumParams(INF);
	}
	void Execute(sOptions* const options, std::vector<std::string>&  param);
};

class XJre : public IOptions{
public:
	XJre(){
		SetNumParams(1);
	}
	void Execute(sOptions* const options, std::vector<std::string>&  param);
};

#endif