/**
 * Boxama
 * Copyright (C) 2023 Jozef Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <signal.h>

#include <boxama.h>
#include <draw.h>

SDL_Window *g_window;

int main()
{
	atexit(die);
	signal(SIGINT, exit);

	SDL_Init(SDL_INIT_VIDEO);

	g_window = SDL_CreateWindow("Boxama 0.1", SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED, 1280, 720,
								SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN);

	SDL_Surface *screen = SDL_GetWindowSurface(g_window);
	SDL_FillRect(screen, 0, 0);

	SDL_UpdateWindowSurface(g_window);

	SDL_Event e;
	while (SDL_WaitEvent(&e) && e.type != SDL_QUIT)
		;

	return 0;
}

void die()
{
	SDL_DestroyWindow(g_window);
	SDL_Quit();
}