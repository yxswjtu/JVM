#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_



#include "options_factory.hpp"

class Options{
private:
	sOptions *options_;
	OptionsFactory *op_factory_;
public:
	void Init();
	void Release();
	void Parse(int argc, char* argv[]);
};

#endif