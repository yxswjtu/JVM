#include "ioptions.hpp"

void XJre::Execute(sOptions* const options, std::vector<std::string>& param){
	if (options && param.size()){
		options->jrepath.swap(param[0]);
	}
}