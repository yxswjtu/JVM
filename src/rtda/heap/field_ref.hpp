#ifndef __FIELD_REF_HPP_
#define __FIELD_REF_HPP_

#include "member_ref.hpp"
#include "field.hpp"
#include "../../classfile/constant_pool/constant_filedref_info.hpp"

namespace jvm{
	namespace rtda{
		namespace heap{
			class FieldRef :public MemberRef{
			private:
				void __resolve_field_ref();
				Field* __lookup_field(Clase* c, std::string& name, std::string& descriptor);
			private:
				Field*  field_;
			public:				
				FieldRef(ConstantPool*cp, jvm::classfile::ConstantFiledrefInfo* refinfo);
				Field* ResolvedField();
				Field* getField();
			};
		}
	}
}



#endif