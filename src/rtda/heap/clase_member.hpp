#ifndef __CLASS_MEMBER_HPP_
#define __CLASS_MEMBER_HPP_

#include "access_flag.hpp"
#include "../../classfile/fileds/member_info.hpp"
#include <string>

namespace jvm{
	namespace rtda{
		namespace heap{
			class Clase;
			class ClaseMember{
			private:
				uint16 access_flags_;
				std::string  name_;
				std::string  descriptor_;
				Clase*       clase_;
			public:
				bool IsPublic();
				bool IsPrivate();
				bool IsProtected();
				bool IsStatic();
				bool IsFinal();
				bool IsSynthetic();
				bool isAccessibleTo(Clase* other);					
				//
				void copyMemberInfo(jvm::classfile::MemberInfo* memberinfo);
				//getter
				uint16 getAccessFlags();
				std::string getName();
				std::string getDescriptor();
				Clase* getClase();
				//setter
				void setClase(Clase* clase);
			};
		}
	}
}

#endif