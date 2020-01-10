#include "SDL.h"
#include "FilledRectangle.h"
#include "FilledTriangle.h"
#include "FilledCircle.h"
#include "time.h"
#include <vector>
#include <iostream>

using namespace std;

void testRendering(vector<Shape*>* shapes, SDL_Renderer *renderer) { // renders a shape vector
	for (int i = 0; i < shapes->size(); i++) {
		(*shapes)[i]->render(renderer);
	}
}

void randomValues(int* r, int *g, int *b, int *a, int *posX, int *posY, int *size, int *width, unsigned int *rgba) { // function generates random values for the shapes
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

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Whac-a-shape", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 1080, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 100, 0, 175, 150);
	SDL_RenderPresent(renderer);

	vector<Shape*> shapes;
	vector<Shape*> lives; // used to render three lives at the top left of the screen
	for (int i = 0; i < 3; i++) {
		lives.push_back(new FilledRectangle(20, 20, Point2D(20 + 25 * i, 20), 0xff0000ff));
	}

	srand((unsigned int)time(NULL));
	int r, g, b, a, posX, posY, size, width;
	unsigned int rgba;

	FilledRectangle* goalRect = new FilledRectangle();
	FilledTriangle* tri = new FilledTriangle();
	FilledCircle* cir = new FilledCircle();
	int points = 0;

	bool quit = false;
	bool spawnNew = true;
	bool stage2 = false;

	int deathTimer = -300; // timer to keep count to put pressure on the player
	int deathAt = 120; // when the timer reaches this number the player loses

	int mousePosX, mousePosY;

	while (!quit) {
		while (SDL_PollEvent(&event)) {

			if (spawnNew) { // randomly generating a circle and triangle
				randomValues(&r, &g, &b, &a, &posX, &posY, &size, &width, &rgba);
				delete goalRect;
				goalRect = new FilledRectangle(size, width, Point2D(posX, posY), rgba);
				goalRect->render(renderer);
				randomValues(&r, &g, &b, &a, &posX, &posY, &size, &width, &rgba);
				delete tri;
				tri = new FilledTriangle(size, width, Point2D(posX, posY), rgba);
				tri->render(renderer);
				spawnNew = false;
				stage2 = true;
			}
			
			if (points > 15 && stage2) { // when the player has clicked 15 rectangles circles start spawning too
				randomValues(&r, &g, &b, &a, &posX, &posY, &size, &width, &rgba);
				delete cir;
				cir = new FilledCircle(size / 2, Point2D(posX, posY), rgba);
				cir->render(renderer);
				stage2 = false;
			}

			if (event.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&mousePosX, &mousePosY);
				if (tri->hitbox(mousePosX, mousePosY) || cir->hitbox(mousePosX, mousePosY)) { // if you click a triangle or circle
					Shape* temp = lives.back(); // removing one life
					lives.pop_back();
					delete temp;
					clearWindow(&shapes, renderer);
					spawnNew = true; // setting this bool to true to generate new targets
				}
				if (goalRect->hitbox(mousePosX, mousePosY)) { //clicking a rectangle grants the player one point
					points++;
					cout << points << endl;
					clearWindow(&shapes, renderer);
					spawnNew = true; // setting this bool to true to generate new targets
					deathTimer = 0;
				}

			}

			switch (event.type) {

			case SDL_KEYDOWN: {
				switch (event.key.keysym.sym) {

				case SDLK_q: { //Alternative qutting key
					quit = true;
					break;
				}
					break;
				}
				break;
			}


			case SDL_QUIT: { //For if user tries to use alt f4 or the X to quit the program
				quit = true;
				break;
			}
				break;
			}
		}
		if (points >= 15 && deathTimer >= 60) { //Increasing difficulty further into the game by decreasing time until losing.
			deathAt--;
		}

		if (lives.size() <= 0 || deathTimer >= deathAt) { // If all lives are lost or the timer goes to 120 the screen flashes red and white before quitting the program.
			for (int i = 0; i < 4; i++) {
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
				SDL_Delay(100);
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
				SDL_Delay(100);
			}
			cout << endl << "------------------------------------------------" << endl << "Score achieved: " << points << endl;
			quit = true;
		}

		testRendering(&lives, renderer);
		SDL_RenderPresent(renderer);
		SDL_Delay(17); //approximately one frame of delay in 60 fps before executing the next iteration
		deathTimer++; //counting up the timer every iteration
		cout << "Death timer: " << deathTimer << endl;
	}

	delete goalRect; //Memory deallocation
	delete tri;
	delete cir;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}