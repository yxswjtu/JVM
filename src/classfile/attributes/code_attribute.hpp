#ifndef __CODE_ATTRIBUTE_HPP_
#define __CODE_ATTRIBUTE_HPP_

#include "attribute_info.hpp"
#include "../constant_pool/constant_pool.hpp"
#include "attributes.hpp"
#include <vector>


namespace jvm{
	namespace classfile{
		class ClassFile;
		class ExceptionEntry{
		private:
			uint16 start_pc_;
			uint16 end_pc_;
			uint16 handler_pc_;
			uint16 catch_type_;
		public:
			ExceptionEntry(jvm::util::ClassReader* rd){
				start_pc_ = rd->readUint16();
				end_pc_ = rd->readUint16();
				handler_pc_ = rd->readUint16();
				catch_type_ = rd->readUint16();
			}
		};

		class CodeAttribute : public AttributeInfo {
		private:
			uint16 max_stack_;
			uint16 max_locals_;			
			uint8* code_;	
			uint32 code_length_;
			std::vector<ExceptionEntry*> exception_table_;
			std::vector<AttributeInfo*> attributs_;	
			ConstantPool* cp_;
			Attributes attributs_reader_;
		private:
			void __read_exception_table(jvm::util::ClassReader* rd);			
		public:		
			void readInfo(jvm::util::ClassReader* rd);		
			CodeAttribute(ConstantPool* cp);
			~CodeAttribute();

			uint16 getMaxStack();
			uint16 getMaxLocals();
			uint8* getCode();
			uint32 getCodeLength();
			std::vector<ExceptionEntry*> getExceptionTable();
		};
	}
}
#endif