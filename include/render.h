#ifndef RENDER_H
#define RENDER_H
#include "../include/particle.h"
void Render_renderParticle(struct Particle *particle);
void Render_init();
void Render_clear(Color_t color);
void Render_present();
void render_destroy();
#endif
