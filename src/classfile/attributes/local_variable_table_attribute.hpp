#ifndef __LOCAL_VARIABLE_TABLE_ATTRIBUTE_HPP_
#define __LOCAL_VARIABLE_TABLE_ATTRIBUTE_HPP_

/*
LocalVariableTable_attribute {
u2 attribute_name_index;
u4 attribute_length;
u2 local_variable_table_length;
{   u2 start_pc;
u2 length;
u2 name_index;
u2 descriptor_index;
u2 index;
} local_variable_table[local_variable_table_length];
}
*/

#include"attribute_info.hpp"
#include <vector>

namespace jvm{
	namespace classfile{
		class LocalVariableTableEntry{
		public:
			uint16 start_pc_;
			uint16 length_;
			uint16 name_index_;
			uint16 descriptor_index_;
			uint16 index_;

			LocalVariableTableEntry(){}
			~LocalVariableTableEntry(){}

			LocalVariableTableEntry(const LocalVariableTableEntry& src){
				start_pc_ = src.start_pc_;
				length_ = src.length_;
				name_index_ = src.name_index_;
				descriptor_index_ = src.descriptor_index_;
				index_ = src.index_;
			}
		};

		class LocalvariableTableAttribute :public AttributeInfo{
		private:
			uint16  local_variable_table_length_;
			std::vector<LocalVariableTableEntry>  local_variable_table_;
		public:
			void readInfo(jvm::util::ClassReader* rd){				
				local_variable_table_length_ = rd->readUint16();
				local_variable_table_.reserve(local_variable_table_length_);

				for (unsigned short i = 0; i < local_variable_table_length_; i++){
					LocalVariableTableEntry tmp;
					tmp.start_pc_ = rd->readUint16();
					tmp.length_ = rd->readUint16();
					tmp.name_index_ = rd->readUint16();
					tmp.descriptor_index_ = rd->readUint16();
					tmp.index_ = rd->readUint16();
					local_variable_table_.push_back(tmp);
				}
			}
		};
	}
}





#endif