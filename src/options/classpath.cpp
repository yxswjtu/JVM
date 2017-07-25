#include "ioptions.hpp"

void ClassPath::Execute(sOptions* const options, std::vector<std::string>& param){
	
	if (options && param.size()){
		options->classpath.swap(param[0]);
	}
}