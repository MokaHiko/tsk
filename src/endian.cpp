#include "tsk/endian.h"

namespace tsk {

Endianness get_platform_endianess() {
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01020304};

    return (bint.c[0] == 1) ? Endianness::k_big_endian : Endianness::k_little_endian;
}

} // namespace tsk
