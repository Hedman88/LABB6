#include "SDL.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "time.h"
#include <vector>
#include <iostream>

using namespace std;

void testRendering(vector<Shape*>* shapes, SDL_Renderer *renderer) {
	for (int i = 0; i < shapes->size(); i++) {
		(*shapes)[i]->render(renderer);
	}
}
/*
int main() {

	vector<Shape*> shapes;
	Rectangle a(5, 7, Point2D(1, 1), 0xff0000ff);
	Triangle b(3, 10, Point2D(1, 5), 0x00ff00ff);
	Circle c(2, Point2D(0, 0), 0x0000ffff);
	shapes.push_back(&a);
	shapes.push_back(&b);
	shapes.push_back(&c);

	testRendering(shapes);

	system("pause");
	return 0;
}
*/
int main(int argc, char *argv[]) {

	vector<Shape*> shapes;
	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Whac-a-shape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 680, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 100, 0, 175, 150);
	SDL_RenderPresent(renderer);

	srand((unsigned int)time(NULL));
	int r, g, b, a, posX, posY, size, width;
	unsigned int rgba;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			r = rand() % 256;
			g = rand() % 256;
			b = rand() % 256;
			a = rand() % 206 + 50;
			rgba = r << 8;
			rgba = (rgba + g) << 8;
			rgba = (rgba + b) << 8;
			rgba = (rgba + a);

			posX = rand() % 1100;
			posY = rand() % 600;
			size = rand() % 250 + 50;
			width = rand() % 250 + 50;


			switch (event.type) {

			case SDL_KEYDOWN: {
				switch (event.key.keysym.sym) {

				case SDLK_c: {
					Circle* c = new Circle(size, Point2D(posX, posY), rgba);
					//shapes.push_back(c);
					c->render(renderer);
					break;
				}
				case SDLK_r: {
					Rectangle* a = new Rectangle(size, width, Point2D(posX, posY), rgba);
					//shapes.push_back(a);
					a->render(renderer);
					break;
				}
				case SDLK_t: {
					Triangle* b = new Triangle(size, width, Point2D(posX, posY), rgba);
					//shapes.push_back(b);
					b->render(renderer);
					break;
				}
				case SDLK_x: {
					//shapes.clear();
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
					SDL_RenderClear(renderer);
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


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}