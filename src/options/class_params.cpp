#include "ioptions.hpp"

void ClassPathParams::Execute(sOptions* const options, std::vector<std::string>& param){
	if (options && param.size()){
		options->classparmas.swap(param);
	}
}