#ifndef __SYMREF_HPP_
#define __SYMREF_HPP_

#include "clase.hpp"

namespace jvm{
	namespace rtda{
		namespace heap{		
			class SymRef{
			private:
				void __resolved_class();
			public:
				std::string clase_name_;
				ConstantPool* cp_;
				//the target reference class
				Clase*  clase_;
			public:				
				Clase* getClass();
				std::string getClassName();
				ConstantPool* getConstant();
				Clase* ResolvedClass();
			};
		}
	}
}



#endif