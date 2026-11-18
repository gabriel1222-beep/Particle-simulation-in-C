#ifndef COLOR_H
#define COLOR_H
#include <stdint.h>
typedef enum Color_t {
    COLOR_BLACK,
    COLOR_WHITE,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_YELLOW,
    COLOR_CYAN,
    COLOR_MAGENTA,

    N_OF_COLORS
} Color_t;
extern const uint8_t rgb_table[N_OF_COLORS][4];
void Color_loadRGBA(uint8_t dest[static 4],Color_t color);
#endif
