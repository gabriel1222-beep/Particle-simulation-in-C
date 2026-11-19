#include "../include/particle.h"
#include "../include/render.h"
#include "../include/color.h"
int main(){
  struct Particle particle = Particle_new(100, 100, 10, COLOR_CYAN);
  Render_init();
  while(1){
    Render_clear(COLOR_BLACK);
    Render_renderParticle(&particle);
    Render_present();
  }
  render_destroy();
}
