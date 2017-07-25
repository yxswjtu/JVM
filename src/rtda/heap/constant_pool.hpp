#ifndef __CLASE_CONSTANT_POOL_HPP_
#define __CLASE_CONSTANT_POOL_HPP_

#include "./helper/any.hpp"
#include "../../classfile/constant_pool/constant_info.hpp"
#include "../../classfile/constant_pool/constant_pool.hpp"
#include <vector>

namespace jvm{
	namespace rtda{
		namespace heap{
			class Clase;

			template<typename ValueType>
			ValueType getConstant(std::vector<Any*>& constants, uint32 index){
				return constants[index]->any_cast<ValueType>();
			}

			class ConstantPool{
			private:
				std::vector<Any*> constants_;
				Clase* clase_;
				std::vector<jvm::classfile::CONSTANT_INFO_TAG> constants_type_;
			private:
				void __copy_constant_pool(jvm::classfile::ConstantPool* pool);
			public:
				ConstantPool(Clase* clase, jvm::classfile::ConstantPool* pool);
				Clase* getClase();
				std::vector<Any*>& getConstants();
				std::vector<jvm::classfile::CONSTANT_INFO_TAG> getConstantType();
				~ConstantPool();				
			};

			
		}
	}
}



#endif