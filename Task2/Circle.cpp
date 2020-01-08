#include "Circle.h"
#include <iostream>
#include <math.h>

using namespace std;

Circle::Circle(float radius, Point2D position, unsigned int RGBA) : Shape(position, RGBA)
{
	this->radius = radius;
}


Circle::~Circle()
{
}

void Circle::render(SDL_Renderer *renderer) {
	cout << endl << "---Circle---" << endl << "Position: " << position.toString() << endl << "Radius: " << radius << endl;
	int r, g, b, a;
	r = RGBA >> 24;
	g = RGBA << 8; g = g >> 24;
	b = RGBA << 16; b = b >> 24;
	a = RGBA << 24; a = a >> 24;
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	int k = 360;
	double twoPi = 2 * M_PI;
	for (int w = 0; w < radius * 2; w++)
	{
		int x, y, x2, y2;
		int dx = radius - w;
		int dy = SDL_sqrt((radius*radius)-(dx*dx));
		x = dx;
		y = dy;
		x2 = dx;
		y2 = -dy;
		SDL_RenderDrawLine(renderer, position.getX() + x, position.getY() + y, position.getX() + x2, position.getY() + y2);
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, a);
	for (int i = 0; i < k; i++) {
		SDL_RenderDrawLineF(renderer, 
			position.getX() + cos((twoPi / k)*i)*radius, position.getY() + sin((twoPi / k)*i)*radius,
			position.getX() + cos((twoPi / k)*(i+1))*radius, position.getY() + sin((twoPi / k)*(i+1))*radius);
	}
}

const float Circle::getRadius() {
	return radius;
}
void Circle::setRadius(float width) {
	this->radius = radius;
}
