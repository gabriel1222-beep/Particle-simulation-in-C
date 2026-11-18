#include "../include/color.h"

void Color_loadRGBA(uint8_t dest[static 4],Color_t color){
  dest[0]=rgb_table[color][0];
  dest[1]=rgb_table[color][1];
  dest[2]=rgb_table[color][2];
  dest[3]=rgb_table[color][3];
}
