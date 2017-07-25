#ifndef __CLASE_FILED_HPP_
#define __CLASE_FILED_HPP_

#include "clase_member.hpp"

namespace jvm{
	namespace rtda{
		namespace heap{
			class Field :public ClaseMember{
			private:
				uint16 const_value_index_;
				uint16 slot_id_;
			public:
				void copyAttributes(jvm::classfile::MemberInfo* info);
			public:
				Field();

				std::vector<Field*> newFields(Clase* clase, std::vector<jvm::classfile::MemberInfo*>& fields);
				bool IsLongOrDouble();
				//getter
				uint16 getSlotId();
				uint16 getConstValueIndex();
				//setter
				void setSlotId(uint16 sid);
				bool IsVolatile();
				bool IsTransient();
				bool IsEnum();
			};
		}
	}
}


#endif