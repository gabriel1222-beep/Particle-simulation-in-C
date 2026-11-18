#ifndef PARTICLE_H
#define PARTICLE_H
#include <stdint.h>
#include "color.h"
struct Particle{
    int x,y;
    int radius;
    Color_t color;
};
struct Particle Particle_new(const int x, const int y,const int radius ,const Color_t color);
#endif
