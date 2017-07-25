#include <iostream>
#include "ioptions.hpp"

void HelpOption::Execute(sOptions* const options, std::vector<std::string>& param){
	std::cout << "help" << std::endl;
}