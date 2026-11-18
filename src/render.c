#include "../include/particle.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>
#include <SDL_blendmode.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
void printErr(const char *str, const char *SDL_error) {
  printf("[\x1b[91mERROR\x1b[0m]: %s -> %s", str, SDL_error);
  fflush(stderr);
}
static SDL_Window *window;
static SDL_Renderer *render;
static SDL_Texture *ball_texture;
void render_destroy(){
   SDL_DestroyRenderer(render); 
   SDL_DestroyWindow(window);
   SDL_DestroyTexture(ball_texture);
}
void Render_init() {
  if (SDL_Init(SDL_INIT_EVENTS) != 0) {
    goto exitErrorSDL;
  }
  Uint32 flag = SDL_WINDOWPOS_UNDEFINED;
  window = SDL_CreateWindow("Particle Simulator", flag, flag, 500, 500,
                            SDL_WINDOW_FULLSCREEN_DESKTOP);
  if (!window) {
    goto exitErrorSDL;
  }
  render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!render) {
    goto exitErrorSDL;
  }
  ball_texture = IMG_LoadTexture(render, "ball.png");
  if (SDL_SetTextureBlendMode(ball_texture, SDL_BLENDMODE_BLEND) != 0) {
    goto exitErrorSDL_img;
  }
  return;
exitErrorSDL:
  printErr("Failed to init SDL", SDL_GetError());
  goto exit;
exitErrorSDL_img:
  printErr("Failed to init SDL", IMG_GetError());
exit:
  exit(EXIT_FAILURE);
}
void Render_clear(Color_t color) {
  SDL_SetRenderDrawColor(render, rgb_table[color][0], rgb_table[color][1], rgb_table[color][2],
                         rgb_table[color][3]);
  SDL_RenderClear(render);
}
void Render_renderParticle(struct Particle *particle) {
  SDL_SetTextureColorMod(ball_texture, rgb_table[particle->color][0],
                         rgb_table[particle->color][1], rgb_table[particle->color][2]);

  SDL_Rect dst = {particle->x - particle->radius,
                  particle->y - particle->radius, particle->radius * 2,
                  particle->radius * 2};

  SDL_RenderCopy(render, ball_texture, NULL, &dst);
}
void Render_present(){
  SDL_RenderPresent(render);
}
