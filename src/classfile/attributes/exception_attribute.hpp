#ifndef __EXCEPTION_HPP_
#define __EXCEPTION_HPP_

#include "attribute_info.hpp"

namespace jvm{
	namespace classfile{
		class ExceptionAttribute :public AttributeInfo{
		private:
			uint16 number_of_exception_;
			uint16* exception_table_;
		public:
			ExceptionAttribute(){ exception_table_ = NULL; }
			~ExceptionAttribute(){ delete exception_table_; }

			void readInfo(jvm::util::ClassReader* rd){				
				exception_table_ = rd->readUint16s(&number_of_exception_);
			}
		};

	}
}


#endif