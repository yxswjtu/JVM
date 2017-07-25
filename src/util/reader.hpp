#ifndef __READR_HPP_
#define __READR_HPP_

#include "../common/global.hpp"
#include <fstream>
#include <strstream>

namespace jvm{
	namespace util{
		class ClassReader{		
		private:			
			uint16    convert(uint16 x);
			uint32    convert(uint32 x);
			uint64    convert(uint64 x);
			float32  convert(float32 x);
			float64  convert(float64 x);			
		private:
			std::strstream* str_stream_;
		public:
			ClassReader(int8* buf, uint32 length);
			~ClassReader();
			uint8   readUint8();
			uint16  readUint16();
			uint32  readUint32();
			uint64  readUint64();
			float32 readFloat32();
			float64 readFloat64();

			//the memory needs to be released by the caller
			uint16* readUint16s(uint16* len=NULL);
			//the memory needs to be released by the caller
			int8*   readBytes(uint32 n);				
		};

	}
}



#endif