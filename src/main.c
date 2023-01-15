#include "gba.h"
#include "rom_header.h"

INSERT_ROM_HEADER("GBAFIXLESS", "REAL", "23", 1);

int main()
{
    REG_DISPCNT = VIDEO_MODE_3 | VIDEO_BG2_ENABLE;

    MODE3_SCREEN[80][120] = COLOR_RED;
    MODE3_SCREEN[80][136] = COLOR_GREEN;
    MODE3_SCREEN[96][120] = COLOR_BLUE;

    while (true) {}
}
