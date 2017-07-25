#include "options_factory.hpp"

OptionsFactory::~OptionsFactory(){
	OPTIONS_MAP::iterator it = option_map_.begin();
	for (; it != option_map_.end(); it++){
		if (it->second){
			delete it->second;
		}
	}
}

OptionsFactory::OptionsFactory(){

	IOptions* hlp = NULL;
	IOptions* cp = NULL;
	IOptions* cps = NULL;
	IOptions* xjre = NULL;

	hlp = new HelpOption();
	cp = new ClassPath();
	cps = new ClassPathParams();
	xjre = new XJre();

	if ((!hlp) | (!cp) | (!cps) | (!xjre)){
		goto failed;
	}

	option_map_.insert(OPTIONS_MAP::value_type(std::string("--help"), hlp));
	option_map_.insert(OPTIONS_MAP::value_type(std::string("--cp"),   cp));
	option_map_.insert(OPTIONS_MAP::value_type(std::string("--cps"),  cps));
	option_map_.insert(OPTIONS_MAP::value_type(std::string("--Xjre"), xjre));

	return;

failed:
	if (hlp){
		delete hlp;
	}

	if (cp){
		delete cp;
	}

	if (cps){
		delete cps;
	}

	if (xjre){
		delete xjre;
	}
}

IOptions* OptionsFactory::GetOptHandler(std::string& name){

	OPTIONS_MAP::iterator it = option_map_.find(name);

	if (it != option_map_.end()){
		return (IOptions*)(it->second);
	}
	return NULL;
}