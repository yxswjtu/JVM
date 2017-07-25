#include "reader.hpp"

using namespace jvm::util;

ClassReader::ClassReader(int8* buf, uint32 length){
	str_stream_ = new std::strstream(buf, length);
}

ClassReader::~ClassReader(){
	delete str_stream_;
}

uint8 ClassReader::readUint8(){
	int8 tmp = 0;
	str_stream_->read(&tmp, sizeof(int8));
	return uint8(tmp);
}

uint16  ClassReader::readUint16(){
	uint16 tmp = 0;
	str_stream_->read((int8*)&tmp, sizeof(uint16));	
	return  convert(tmp);
}
uint32  ClassReader::readUint32(){
	uint32 tmp = 0;
	str_stream_->read((int8*)&tmp, sizeof(uint32));
	return  convert(tmp);
}
uint64  ClassReader::readUint64(){
	uint64 tmp = 0;
	str_stream_->read((int8*)&tmp, sizeof(uint64));
	return  convert(tmp);
}

float32 ClassReader::readFloat32(){
	float32 tmp;
	str_stream_->read((int8*)&tmp, sizeof(float32));	
	return convert(tmp);
}

float64 ClassReader::readFloat64(){
	float64 tmp;
	str_stream_->read((int8*)&tmp, sizeof(float64));
	return convert(tmp);
}

uint16* ClassReader::readUint16s(uint16* len){
	uint16 n = readUint16();
	uint16* tmp = new uint16[n];

	for (uint32 i = 0; i < n; i++){
		tmp[i] = readUint16();
	}

	if (len){
		*len = n;
	}
	
	return tmp;
}

int8* ClassReader::readBytes(uint32 n){
	int8* tmp = new int8[n];
	str_stream_->read(tmp, n);
	return tmp;
}

uint16  ClassReader::convert(uint16 x) {
	x = ((x & 0xff00) >> 8) | ((x & 0x00ff) << 8);
	return x;
}

uint32  ClassReader::convert(uint32 x) {
	x = ((x & 0xff000000) >> 24) | ((x & 0x000000ff) << 24) | ((x & 0x00ff0000) >> 8) | ((x & 0x0000ff00) << 8);
	return x;
}

float32  ClassReader::convert(float32 x){
	UINT_32 num;
	num.float_ = x;
	num.uint_ = convert(num.uint_);
	return num.float_;
}

float64   ClassReader::convert(float64 value){
	UINT_64 num;
	num.double_ = value;
	num.ulong_ = convert(num.ulong_);
	return num.double_;
}

uint64 ClassReader::convert(uint64 v){
	return (v >> 56)
		| ((v & 0x00ff000000000000) >> 40)
		| ((v & 0x0000ff0000000000) >> 24)
		| ((v & 0x000000ff00000000) >> 8)
		| ((v & 0x00000000ff000000) << 8)
		| ((v & 0x0000000000ff0000) << 24)
		| ((v & 0x000000000000ff00) << 40)
		| (v << 56);
}