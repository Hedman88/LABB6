#include "FilledTriangle.h"
#include <iostream>

using namespace std;

FilledTriangle::FilledTriangle(float base, float height, Point2D position, unsigned int RGBA) : Shape(position, RGBA)
{
	this->base = base;
	this->height = height;
}


FilledTriangle::~FilledTriangle()
{
}

void FilledTriangle::render(SDL_Renderer *renderer) {
	cout << endl << "---Triangle---" << endl << "Position: " << position.toString() << endl << "Base: " << base << endl << "Height: " << height << endl;
	int r, g, b, a;
	r = RGBA >> 24;
	g = RGBA << 8; g = g >> 24;
	b = RGBA << 16; b = b >> 24;
	a = RGBA << 24; a = a >> 24;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for (int w = 0; w < base/2; w++)
	{
		int x, y, x2, y2;
		int dx = base/2 - w;
		int dy = dx*height / (base/2);
		x = dx;
		y = dy;
		x2 = dx;
		y2 = height;
		SDL_RenderDrawLine(renderer, position.getX() + x, position.getY() + y, position.getX() + x2, position.getY() + y2);
		SDL_RenderDrawLine(renderer, position.getX() - x, position.getY() + y, position.getX() - x2, position.getY() + y2);
	}
	SDL_RenderDrawLine(renderer, position.getX(), position.getY(), position.getX(), position.getY() + height);
}

const float FilledTriangle::getBase() {
	return base;
}
const float FilledTriangle::getHeight() {
	return height;
}
void FilledTriangle::setBase(float width) {
	this->base = base;
}
void FilledTriangle::setHeight(float height) {
	this->height = height;
}