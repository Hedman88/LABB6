#pragma once
#include "SDL.h"
#include "Shape.h"

class Circle:public Shape
{
	float radius;
public:
	Circle(float radius, Point2D position, unsigned int RGBA);
	~Circle();
	void render(SDL_Renderer *renderer);
	const float getRadius();
	void setRadius(float radius);
};

