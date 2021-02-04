/**********************************************************************************************************************
    file:           type_arm32.h
    description:    Type definitions for 32-bit ARM
    author:         (C) 2020 PlayerCatboy (Ralf Ren).
    date:           Dec.20, 2020
**********************************************************************************************************************/
#ifndef __TYPE_ARM32_H_
#define __TYPE_ARM32_H_
/**********************************************************************************************************************
    Basic data type definitions
**********************************************************************************************************************/
typedef          int            bool;                                           //  Boolean

typedef          void          *pvoid;                                          //  Pointer to void
typedef const    void          *cpvoid;                                         //  Constant pointer to void

typedef unsigned char           uchar;                                          //  Unsigned character
typedef unsigned char          *puchar;                                         //  Pointer to unsigned character
typedef          char          *pchar;                                          //  Pointer to character
typedef const    char          *cpchar;                                         //  Constant pointer to character

typedef unsigned long           ulong;                                          //  Unsigned long

typedef unsigned int            uint;                                           //  Unsigned integer

typedef signed   char           int8;                                           //  8-bit integer
typedef unsigned char           uint8;                                          //  Unsigned 8-bit integer

typedef          short          int16;                                          //  16-bit integer
typedef unsigned short          uint16;                                         //  Unsigned 16-bit integer

typedef          int            int32;                                          //  32-bit integer
typedef unsigned int            uint32;                                         //  Unsigned 32-bit integer

typedef          long long      int64;                                          //  64-bit integer
typedef unsigned long long      uint64;                                         //  Unsigned 64-bit integer
/**********************************************************************************************************************
    Derived data types definitions
**********************************************************************************************************************/
typedef          void          *omni;                                           //  Data type for any
typedef unsigned long           addr;                                           //  Data type for address
typedef unsigned long           size;                                           //  Data type for size
typedef signed   long           ssize;                                          //  Data type for signed size

#endif                                                                          //  __TYPE_ARM32_H_
/**********************************************************************************************************************
    end
**********************************************************************************************************************/
