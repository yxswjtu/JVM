#ifndef __OPTIONS_FACTORY_
#define __OPTIONS_FACTORY_

#include <map>
#include "ioptions.hpp"
typedef std::map<std::string, IOptions*> OPTIONS_MAP;

class OptionsFactory{	
public:	
	OptionsFactory();
	~OptionsFactory();
	IOptions* GetOptHandler(std::string& name);	

	bool IsOption(std::string& name){
		if (option_map_.find(name) != option_map_.end()){
			return true;
		}

		return false;
	}
private:	
	OPTIONS_MAP option_map_;
};


#endif