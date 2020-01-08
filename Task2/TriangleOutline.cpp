#include "TriangleOutline.h"
#include <iostream>

using namespace std;

TriangleOutline::TriangleOutline(float base, float height, Point2D position) : FilledTriangle(base, height, position, 0xffffffff)
{
}


TriangleOutline::~TriangleOutline()
{
}

void TriangleOutline::render(SDL_Renderer *renderer) {
	cout << endl << "---Triangle---" << endl << "Position: " << position.toString() << endl << "Base: " << base << endl << "Height: " << height << endl;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLineF(renderer, position.getX(), position.getY(), position.getX() + base / 2, position.getY() + height);
	SDL_RenderDrawLineF(renderer, position.getX() + base / 2, position.getY() + height, position.getX() - base / 2, position.getY() + height);
	SDL_RenderDrawLineF(renderer, position.getX() - base / 2, position.getY() + height, position.getX(), position.getY());
}