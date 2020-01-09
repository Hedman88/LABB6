#include "SDL.h"
#include "FilledRectangle.h"
#include "FilledTriangle.h"
#include "FilledCircle.h"
#include "RectangleOutline.h"
#include "TriangleOutline.h"
#include "CircleOutline.h"
#include "time.h"
#include <vector>
#include <iostream>

using namespace std;

void testRendering(vector<Shape*>* shapes, SDL_Renderer *renderer) {
	for (int i = 0; i < shapes->size(); i++) {
		(*shapes)[i]->render(renderer);
	}
}

void randomValues(int* r, int *g, int *b, int *a, int *posX, int *posY, int *size, int *width, unsigned int *rgba) {
	*r = rand() % 256;
	*g = rand() % 256;
	*b = rand() % 256;
	*a = rand() % 206 + 50;
	*rgba = *r << 8;
	*rgba = (*rgba + *g) << 8;
	*rgba = (*rgba + *b) << 8;
	*rgba = (*rgba + *a);

	*posX = rand() % 1400 + 100;
	*posY = rand() % 800 + 100;
	*size = rand() % 250 + 50;
	*width = rand() % 250 + 50;
}

void clearWindow(vector<Shape*>* shapes, SDL_Renderer *renderer) {
	for (int i = 0; i < (*shapes).size(); i++) {
		delete (*shapes)[i];
	}
	(*shapes).clear();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

int main(int argc, char *argv[]) {

	vector<Shape*> shapes;
	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Whac-a-shape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1080, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 100, 0, 175, 150);
	SDL_RenderPresent(renderer);

	srand((unsigned int)time(NULL));
	int r, g, b, a, posX, posY, size, width;
	unsigned int rgba;

	FilledRectangle* goalRect = new FilledRectangle();
	int points = 0;

	int moles = 2;
	bool molesNeeded = true;

	int mousePosX, mousePosY;

	while (!quit) {
		while (SDL_PollEvent(&event)) {

			if (molesNeeded) {
				randomValues(&r, &g, &b, &a, &posX, &posY, &size, &width, &rgba);
				FilledRectangle* a = new FilledRectangle(size, width, Point2D(posX, posY), rgba);
				goalRect = a;
				shapes.push_back(a);
				a->render(renderer);
				molesNeeded = false;
			}
			

			


			if (event.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&mousePosX, &mousePosY);
				if ((mousePosX > goalRect->getPos().getX()) && (mousePosX < goalRect->getPos().getX() + goalRect->getWidth())
					&& (mousePosY > goalRect->getPos().getY()) && (mousePosY < goalRect->getPos().getY() + goalRect->getHeight())) {
					points++;
					cout << points << endl;
					clearWindow(&shapes, renderer);
					molesNeeded = true;
				}

			}
			switch (event.type) {

			case SDL_KEYDOWN: {
				switch (event.key.keysym.sym) {

				case SDLK_x: {
					clearWindow(&shapes, renderer);
					break;
				}
				case SDLK_q: {
					quit = true;
					break;
				}
							 break;
				}
				break;
			}


			case SDL_QUIT: {
				quit = true;
				break;
			}
						   break;
			}
		}
		/*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		testRendering(&shapes, renderer);*/
		SDL_RenderPresent(renderer);
		SDL_Delay(17);
	}

	delete goalRect;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}