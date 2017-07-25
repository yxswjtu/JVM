#include "options.hpp"
#include <iostream>

void Options::Init(){
	options_ = new sOptions();
	op_factory_ = new OptionsFactory();	
}

void Options::Release(){
	if (options_){
		delete options_;
	}

	if (op_factory_){
		delete op_factory_;
	}
}

void Options::Parse(int argc, char* argv[]){	
	std::string op;	
	std::vector<std::string> params;

	for (int i = 1; i < argc; i++){	
		params.clear();
		op = std::string(argv[i]);
		if (op_factory_->IsOption(std::string(op))){
			IOptions* iop = op_factory_->GetOptHandler(op);
			if (iop){
				
				if (iop->GetNumParams() == 0){
					iop->Execute(options_, params);

				}else if (iop->GetNumParams() != INF){
					i++;
					for (int j = 0;  i<argc && j < iop->GetNumParams(); j++, i++){
						params.push_back(std::string(argv[i]));
					}		
					i--;
					iop->Execute(options_, params);		
				}else{
					i++;
					while (i < argc && false == op_factory_->IsOption(std::string(argv[i]))){
						params.push_back(std::string(argv[i]));
						i++;
					}
					iop->Execute(options_, params);
					i--;
				}
			}					
		}			
	}	
}