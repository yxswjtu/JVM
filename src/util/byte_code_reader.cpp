#include "byte_code_reader.hpp"

BytecodeReader::BytecodeReader(uint8* code,int32 pc) :code_bytes_(code), pc_(pc){

}

int32 BytecodeReader::PC(){
	return pc_;
}

int8 BytecodeReader::ReadInt8() {
	int8 tmp;
	tmp = code_bytes_[pc_];
	pc_++;
	return tmp;
}

uint8 BytecodeReader::ReadUint8() {
	uint8 tmp;
	tmp = code_bytes_[pc_];
	pc_++;
	return tmp;
}

int16 BytecodeReader::ReadInt16() {
	int16 byte1 = ReadUint8();
	int16 byte2 = ReadUint8();
	
	return (byte1 << 8) | byte2;
}

uint16 BytecodeReader::ReadUint16() {
	uint16 byte1 = ReadUint8();
	uint16 byte2 = ReadUint8();
	return (byte1 << 8) | byte2;
}

int32 BytecodeReader::ReadInt32() {
	int32 byte1 = ReadUint8();
	int32 byte2 = ReadUint8();
	int32 byte3 = ReadUint8();
	int32 byte4 = ReadUint8();
	return (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
}

std::vector<int32> BytecodeReader::ReadInt32s(int32 n){
	std::vector<int32> res;

	res.resize(n);
	for (int i = 0; i < n; i++){
		res[i] = ReadInt32();
	}
	return res;
}

void BytecodeReader::SkipPadding(){
	while ((pc_ % 4) != 0){
		ReadUint8();
	}
}

void BytecodeReader::Reset(int32 pc){
	pc_ = pc;
}