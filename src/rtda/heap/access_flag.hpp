#ifndef __ACCESS_HPP_
#define __ACCESS_HPP_

#include "../../common/global.hpp"

#define ACC_PUBLIC        (uint16)0x0001 // class field method
#define ACC_PRIVATE       (uint16)0x0002 //       field method
#define ACC_PROTECTED     (uint16)0x0004 //       field method
#define ACC_STATIC        (uint16)0x0008 //       field method
#define ACC_FINAL         (uint16)0x0010 // class field method
#define ACC_SUPER         (uint16)0x0020 // class
#define ACC_SYNCHRONIZED  (uint16)0x0020 //             method
#define ACC_VOLATILE      (uint16)0x0040 //       field
#define ACC_BRIDGE        (uint16)0x0040 //             method
#define ACC_TRANSIENT     (uint16)0x0080 //       field
#define ACC_VARARGS       (uint16)0x0080 //             method
#define ACC_NATIVE        (uint16)0x0100 //             method
#define ACC_INTERFACE     (uint16)0x0200 // class
#define ACC_ABSTRACT      (uint16)0x0400 // class       method
#define ACC_STRICT        (uint16)0x0800 //             method
#define ACC_SYNTHETIC     (uint16)0x1000 // class field method
#define ACC_ANNOTATION    (uint16)0x2000 // class
#define ACC_ENUM          (uint16)0x4000 // class field

#endif