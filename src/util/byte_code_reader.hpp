#ifndef __BYTE_CODE_READER_HPP_
#define __BYTE_CODE_READER_HPP_

#include "../common/global.hpp"
#include <vector>

class BytecodeReader{
private:
	uint8 * code_bytes_;	
	int32   pc_;
	int32   code_length_;
public:
	BytecodeReader(uint8 * code, int32 pc);
	int32 PC();
	int8 ReadInt8();
	uint8 ReadUint8();
	int16 ReadInt16();
	uint16 ReadUint16();
	int32 ReadInt32();
	std::vector<int32> ReadInt32s(int32 n);
	void SkipPadding();
	void Reset(int32 pc);
};

#endif