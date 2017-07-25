#ifndef __LINE_NUMBER_TABLE_ATTRIBUTE_HPP_
#define __LINE_NUMBER_TABLE_ATTRIBUTE_HPP_

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

#include "attribute_info.hpp"
#include <vector>

namespace jvm{
	namespace classfile{
		class LineNumberTableEntry{
		private:
			uint16 start_pc_;
			uint16 line_number_;
		public:
			LineNumberTableEntry(const LineNumberTableEntry& src){
				start_pc_ = src.start_pc_;
				line_number_ = src.line_number_;
			}

			LineNumberTableEntry(){};

			void setStartPC(uint16 pc){
				start_pc_ = pc;
			}

			void setLineNumber(uint16 num){
				line_number_ = num;
			}
		};

		class LinenumberTableAttribute :public AttributeInfo{
		private:
			uint16 line_number_table_length_;
			std::vector<LineNumberTableEntry> line_number_table_;
		public:
			void readInfo(jvm::util::ClassReader* rd){
				line_number_table_length_ = rd->readUint16();
				line_number_table_.reserve(line_number_table_length_);

				for (unsigned short i = 0; i < line_number_table_length_; i++){
					LineNumberTableEntry tmp;
					tmp.setStartPC(rd->readUint16());
					tmp.setLineNumber(rd->readUint16());					
					line_number_table_.push_back(tmp);
				}
			}			
		};
	}
}


#endif