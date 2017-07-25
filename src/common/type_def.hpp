#ifndef __TYPE_DEF_HPP_
#define __TYPE_DEF_HPP_

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int   int32;
typedef unsigned int   uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef float float32;
typedef double float64;

typedef union UINT_32{
		uint32  uint_;
		float32 float_;
}INT_32;

typedef union UINT_64{
	float64  double_;
	uint64    ulong_;
}INT_64;




#endif