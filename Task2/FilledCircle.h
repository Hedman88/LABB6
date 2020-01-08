#pragma once
#include "SDL.h"
#include "Shape.h"

class FilledCircle:public Shape
{
	float radius;
public:
	FilledCircle(float radius, Point2D position, unsigned int RGBA);
	~FilledCircle();
	void render(SDL_Renderer *renderer);
	const float getRadius();
	void setRadius(float radius);
};

