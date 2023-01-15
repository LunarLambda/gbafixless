#ifndef _ROM_HEADER_H
#define _ROM_HEADER_H

#define CHECKSUM(title, gamecode, makercode, version) \
(unsigned char)(- 0x19 \
- ((title    )[sizeof(title    ) <=  0 ? sizeof(title    ) - 1 :  0]) \
- ((title    )[sizeof(title    ) <=  1 ? sizeof(title    ) - 1 :  1]) \
- ((title    )[sizeof(title    ) <=  2 ? sizeof(title    ) - 1 :  2]) \
- ((title    )[sizeof(title    ) <=  3 ? sizeof(title    ) - 1 :  3]) \
- ((title    )[sizeof(title    ) <=  4 ? sizeof(title    ) - 1 :  4]) \
- ((title    )[sizeof(title    ) <=  5 ? sizeof(title    ) - 1 :  5]) \
- ((title    )[sizeof(title    ) <=  6 ? sizeof(title    ) - 1 :  6]) \
- ((title    )[sizeof(title    ) <=  7 ? sizeof(title    ) - 1 :  7]) \
- ((title    )[sizeof(title    ) <=  8 ? sizeof(title    ) - 1 :  8]) \
- ((title    )[sizeof(title    ) <=  9 ? sizeof(title    ) - 1 :  9]) \
- ((title    )[sizeof(title    ) <= 10 ? sizeof(title    ) - 1 : 10]) \
- ((title    )[sizeof(title    ) <= 11 ? sizeof(title    ) - 1 : 11]) \
- ((gamecode )[sizeof(gamecode ) <=  0 ? sizeof(gamecode ) - 1 :  0]) \
- ((gamecode )[sizeof(gamecode ) <=  1 ? sizeof(gamecode ) - 1 :  1]) \
- ((gamecode )[sizeof(gamecode ) <=  2 ? sizeof(gamecode ) - 1 :  2]) \
- ((gamecode )[sizeof(gamecode ) <=  3 ? sizeof(gamecode ) - 1 :  3]) \
- ((makercode)[sizeof(makercode) <=  0 ? sizeof(makercode) - 1 :  0]) \
- ((makercode)[sizeof(makercode) <=  1 ? sizeof(makercode) - 1 :  1]) \
- 0x96 \
- (version))

#define INSERT_ROM_HEADER(title, gamecode, makercode, version) \
const __attribute__((section(".header_data"))) struct { \
    char _title[12]; \
    char _gamecode[4]; \
    char _makercode[2]; \
    unsigned char _hex; \
    unsigned char _pad[9]; \
    unsigned char _version; \
    unsigned char _checksum; \
    unsigned char _pad2[2]; \
} _header = { title, gamecode, makercode, 0x96, {0}, version, \
     CHECKSUM(title, gamecode, makercode, version), {0}, }

#endif
