/* -------------------------------------------------------------------------
@file main.c

@date 12/01/16 10:32:10
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
SDL hola mundo
@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SCREEN_WIDTH  720
#define SCREEN_HEIGHT 720

void render_screen(SDL_Renderer* renderer, SDL_Texture* screen);

int main(void)
{
   SDL_Init(SDL_INIT_VIDEO);
   SDL_Window* window = SDL_CreateWindow("SDL hello world",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SCREEN_WIDTH, SCREEN_HEIGHT,
                                        0);

   SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_SOFTWARE);
   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

   SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

   SDL_Texture* screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);

   bool done = false;
   while (!done) {
      SDL_Event event;
      while (SDL_PollEvent(&event) != 0) {
         if (event.type == SDL_QUIT) {
            done = true;
            break;
         }
      }
      render_screen(renderer, screen);
   }

   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
   return 0;
}

void render_screen(SDL_Renderer* renderer, SDL_Texture* screen) {
   uint32_t* pixels = calloc(SCREEN_WIDTH * SCREEN_HEIGHT, sizeof(uint32_t));
   SDL_UpdateTexture(screen, NULL, pixels, SCREEN_WIDTH * sizeof(uint32_t));
   SDL_RenderClear(renderer);
   SDL_RenderCopy(renderer, screen, NULL, NULL);
   SDL_RenderPresent(renderer);
}
