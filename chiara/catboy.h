/**********************************************************************************************************************
    file:           catboy.h
    description:    Catboy's useful debugging tools
    author:         (C) 2020 PlayerCatboy (Ralf Ren).
    date:           Dec.30, 2020
**********************************************************************************************************************/
#ifndef __CATBOY_H_
#define __CATBOY_H_
/**********************************************************************************************************************
    ____    __           ______    ___    ______   ______    ____    ___   ______   ____     ____     ______
   /  _/   / /          / ____/   /   |  / ____/  / ____/   /  _/   /   | /_  __/  / __ \   / __ \   / ____/
   / /    / /          / /       / /| | / /      / /        / /    / /| |  / /    / / / /  / /_/ /  / __/
 _/ /    / /___       / /___    / ___ |/ /___   / /___    _/ /    / ___ | / /    / /_/ /  / _, _/  / /___
/___/   /_____/       \____/   /_/  |_|\____/   \____/   /___/   /_/  |_|/_/     \____/  /_/ |_|  /_____/
    ____     ______    __     __     ___            _   __   ____   ______  ______    ______
   / __ \   / ____/   / /    / /    /   |          / | / /  / __ \ /_  __/ /_  __/   / ____/
  / / / /  / __/     / /    / /    / /| |         /  |/ /  / / / /  / /     / /     / __/
 / /_/ /  / /___    / /___ / /___ / ___ |        / /|  /  / /_/ /  / /     / /     / /___
/_____/  /_____/   /_____//_____//_/  |_|       /_/ |_/   \____/  /_/     /_/     /_____/

    IL CACCIATORE DELLA NOTTE
**********************************************************************************************************************/
#define gtbHeaderVerion(...)                (1)
/**********************************************************************************************************************
    macros for round up and down
**********************************************************************************************************************/
#define gtbRoundUp(x, align)                (unsigned long)(((unsigned long)(x) +  (align - 1)) & ~(align - 1))
#define gtbRoundDown(x, align)              (unsigned long)( (unsigned long)(x) & ~(align - 1))
/**********************************************************************************************************************
    macros for looping
**********************************************************************************************************************/
#define in(var, start, end)                 for ((var) = (start); (var) < (end); (var)++)
#define from(var, start, end)               for ((var) = (start); (var) > (end); (var)--)
#define till(reg, has_bit)                  while (!((reg) & (has_bit)))
#define until(reg, without_bit)             while ((reg) & (without_bit))
#define always                              while (1)
#define forever                             for (;;)
/**********************************************************************************************************************
    macros for showing variable value
**********************************************************************************************************************/
#define __SHOW_METHOD(fmt, ...)             carHwPrintf(fmt, ## __VA_ARGS__)
/*
 *  show variable's name and its value
 */
#define hshow(var)                          __SHOW_METHOD(#var"\t\t= 0x%x\n\r", (var))
#define ishow(var)                          __SHOW_METHOD(#var"\t\t= %d\n\r", (var))
#define sshow(var)                          __SHOW_METHOD(#var"\t\t= %s\n\r", (var))
#define pshow(var)                          __SHOW_METHOD(#var"\t\t= %p\n\r", (var))
/*
 *  show with comment
 */
#define mhshow(comment, var)                __SHOW_METHOD(#comment"\t\t: 0x%x\n\r", (var))
#define mishow(comment, var)                __SHOW_METHOD(#comment"\t\t: %d\n\r", (var))
#define msshow(comment, var)                __SHOW_METHOD(#comment"\t\t: %s\n\r", (var))
#define mpshow(comment, var)                __SHOW_METHOD(#comment"\t\t: %p\n\r", (var))
/*
 *  show array item's name and its value
 */
#define ihshow(array, index)                __SHOW_METHOD(#array"[%d]\t\t= 0x%x\n\r", (index), (array)[(index)])
#define iishow(array, index)                __SHOW_METHOD(#array"[%d]\t\t= %d\n\r", (index), (array)[(index)])
#define isshow(array, index)                __SHOW_METHOD(#array"[%d]\t\t= %s\n\r", (index), (array)[(index)])
#define ipshow(array, index)                __SHOW_METHOD(#array"[%d]\t\t= %p\n\r", (index), (array)[(index)])
/*
 *  show specified array items' name and their value
 */
#define ahshow(array, var, start_index, end_index)      \
    in ((var), (start_index), (end_index)) {            \
        ihshow(array, (var));                           \
    }
#define aishow(array, var, start_index, end_index)      \
    in ((var), (start_index), (end_index)) {            \
        iishow(array, (var));                           \
    }
#define asshow(array, var, start_index, end_index)      \
    in ((var), (start_index), (end_index)) {            \
        isshow(array, (var));                           \
    }
#define apshow(array, var, start_index, end_index)      \
    in ((var), (start_index), (end_index)) {            \
        ipshow(array, (var));                           \
    }
/**********************************************************************************************************************
    macros for memory allocating
**********************************************************************************************************************/
#define __MALLOC_METHOD(size)               carHwMalloc(size)

#define new(type)                           (type *)__MALLOC_METHOD(sizeof(type))
/**********************************************************************************************************************
    description:    Count down
    parameters:     seconds:        Seconds
    return:         none
**********************************************************************************************************************/
void  gtbCountDown (int seconds)
{
    int  i;

    from (i, seconds, 0) {
        __SHOW_METHOD("%i\n", i);
        sleep(1);
    }
}
/**********************************************************************************************************************
    description:    Memory show (8-bit access)
    parameters:     addr:           Start address for showing
                    data:           Data
                    len:            Data length count as bytes
    return:         none
**********************************************************************************************************************/
void  gtbMemShow8 (unsigned long addr, unsigned char *data, unsigned long len)
{
    int     i;
    int     j;
    unsigned long  lines;
    unsigned long  cols;

    if (!data) return;

    lines = gtbRoundDown(len, 16);
    cols  = len & 0xF;

    for (i = 0; i < lines; i += 16) {
        __SHOW_METHOD("%016x    %02x %02x %02x %02x %02x %02x %02x %02x  "
                     "%02x %02x %02x %02x %02x %02x %02x %02x        ",
                     addr + i,
                     data[i + 0 ], data[i + 1 ], data[i + 2 ], data[i + 3 ],
                     data[i + 4 ], data[i + 5 ], data[i + 6 ], data[i + 7 ],
                     data[i + 8 ], data[i + 9 ], data[i + 10], data[i + 11],
                     data[i + 12], data[i + 13], data[i + 14], data[i + 15]);

        in (j, 0, 16) {
            if ((data[i + j] >= 0x20) && (data[i + j] <= 0x7E)) {
                __SHOW_METHOD("%c", data[i + j]);
            } else {
                __SHOW_METHOD(".");
            }
        }
        __SHOW_METHOD("\r\n");
    }

    if (cols) {
        __SHOW_METHOD("%016x    ", addr + lines);
        in (i, 0, cols) {
            if (i == 8) {
                __SHOW_METHOD(" ");
            }
            __SHOW_METHOD("%02x ", data[lines + i]);
        }

        in (i, 0, 16 - cols) {
            __SHOW_METHOD("   ");
        }
        __SHOW_METHOD("       ");

        in (i, 0, cols) {
            if ((data[lines + i] >= 0x20) && (data[lines + i] <= 0x7E)) {
                __SHOW_METHOD("%c", data[lines + i]);
            } else {
                __SHOW_METHOD(".");
            }
        }
        __SHOW_METHOD("\r\n");
    }
}
/**********************************************************************************************************************
    description:    Memory show (32-bit version)
    parameters:     addr:           Start address for showing
                    data:           Data
                    len:            Data length count as bytes
    return:         none
**********************************************************************************************************************/
void  gtbMemShow32 (unsigned long addr, unsigned int *data, unsigned long len)
{
    int  lines = len >> 2;
    int  i;

    in (i, 0, lines) {
        __SHOW_METHOD("0x%x: 0x%08x\r\n", addr, data[i]);
        addr += 4;
    }
}
/**********************************************************************************************************************
    description:    Memory show (16-bit version)
    parameters:     addr:           Start address for showing
                    data:           Data
                    len:            Data length count as bytes
    return:         none
**********************************************************************************************************************/
void  gtbMemShow16 (unsigned long addr, unsigned short *data, unsigned long len)
{
    int  lines = len >> 2;
    int  i;

    in (i, 0, lines) {
        __SHOW_METHOD("0x%x: 0x%04x\r\n", addr, data[i]);
        addr += 2;
    }
}
#endif                                                                          // __CATBOY_H_
/**********************************************************************************************************************
    end
**********************************************************************************************************************/
