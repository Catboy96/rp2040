/**********************************************************************************************************************
    file:           regio.h
    description:    Register Read & Write
    author:         (C) 2020 PlayerCatboy (Ralf Ren).
    date:           Dec.20, 2020
**********************************************************************************************************************/
#ifndef __REGIO_H_
#define __REGIO_H_

#include "type_arm32.h"

#define writeq(data, addr)                  (*(volatile uint64 *)(addr) = (data))
#define writel(data, addr)                  (*(volatile uint32 *)(addr) = (data))
#define writes(data, addr)                  (*(volatile uint16 *)(addr) = (data))
#define writeb(data, addr)                  (*(volatile uint8  *)(addr) = (data))

#define readq(addr)                         (*(volatile uint64 *)(addr))
#define readl(addr)                         (*(volatile uint32 *)(addr))
#define reads(addr)                         (*(volatile uint16 *)(addr))
#define readb(addr)                         (*(volatile uint8  *)(addr))

#define bit(x)                              (1UL << (x))
#define bits(start, end)                    ((0xFFFFFFFFUL << (start)) & (0xFFFFFFFFUL >> (31U - (uint32)(end))))

#endif                                                                          //  __REGIO_H_
/**********************************************************************************************************************
    end
**********************************************************************************************************************/
