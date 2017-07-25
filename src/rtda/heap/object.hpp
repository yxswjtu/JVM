#ifndef __OBJECT_HPP_
#define __OBJECT_HPP_

#include "../heap/clase.hpp"
#include "../stack/slot.hpp"



namespace jvm{
	namespace rtda{	
		namespace heap{
			class Object{
			public:				
				Clase* clase_;				
				Slot*  fields_;
			public:
				Slot* getFields();
				Clase* getClass();
				void   setClass(Clase* clase);
				void   setFields(Slot* field);
				bool IsInstanceOf(Clase* clase);
			};
		}
			
	}
}



#endif