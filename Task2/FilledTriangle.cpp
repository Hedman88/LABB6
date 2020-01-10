#include "FilledTriangle.h"
#include <iostream>

using namespace std;

FilledTriangle::FilledTriangle() {

}

FilledTriangle::FilledTriangle(float base, float height, Point2D position, unsigned int RGBA) : Shape(position, RGBA)
{
	this->base = base;
	this->height = height;
}


FilledTriangle::~FilledTriangle()
{
}

void FilledTriangle::render(SDL_Renderer *renderer) {
	//cout << endl << "---Triangle---" << endl << "Position: " << position.toString() << endl << "Base: " << base << endl << "Height: " << height << endl;
	int r, g, b, a;
	r = RGBA >> 24;
	g = RGBA << 8; g = g >> 24;
	b = RGBA << 16; b = b >> 24;
	a = RGBA << 24; a = a >> 24;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	for (int w = 0; w < base/2; w++) // drawing a filled triangle by finding the correct y coordinates for each x
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
	SDL_RenderDrawLine(renderer, position.getX(), position.getY(), position.getX(), position.getY() + height); // drawing a last line in the middle because there is none if the width of the triangle is even.

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLineF(renderer, position.getX(), position.getY(), position.getX() + base / 2, position.getY() + height);
	SDL_RenderDrawLineF(renderer, position.getX() + base / 2, position.getY() + height, position.getX() - base / 2, position.getY() + height);
	SDL_RenderDrawLineF(renderer, position.getX() - base / 2, position.getY() + height, position.getX(), position.getY());
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
bool FilledTriangle::hitbox(int mouseX, int mouseY) { // checks if mouse is inside the triangle
	float k = height / (base / 2);
	float x = mouseX - position.getX(); // setting x and y to be relative to the triangles position
	float y = mouseY - position.getY();
	if (y < height) { // this checks if the mouse is above the bottom line
		if (y > k * x && y > -k * x) { // this checks if the mouse is below the top left line and the top right line using y = kx + m formula.
			return true;
		}
		return false;
	}
	else {
		return false;
	}
}