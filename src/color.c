#include "../include/color.h"
const uint8_t rgb_table[N_OF_COLORS][4] = {
    [COLOR_BLACK]   = {   0,   0,   0, 255 },
    [COLOR_WHITE]   = { 255, 255, 255, 255 },
    [COLOR_RED]     = { 255,   0,   0, 255 },
    [COLOR_GREEN]   = {   0, 255,   0, 255 },
    [COLOR_BLUE]    = {   0,   0, 255, 255 },
    [COLOR_YELLOW]  = { 255, 255,   0, 255 },
    [COLOR_CYAN]    = {   0, 255, 255, 255 },
    [COLOR_MAGENTA] = { 255,   0, 255, 255 }
};

void Color_loadRGBA(uint8_t dest[static 4],Color_t color){
  dest[0]=rgb_table[color][0];
  dest[1]=rgb_table[color][1];
  dest[2]=rgb_table[color][2];
  dest[3]=rgb_table[color][3];
}
