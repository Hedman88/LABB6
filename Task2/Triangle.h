#pragma once
#include "SDL.h"
#include "Shape.h"
class Triangle:public Shape
{
	float base;
	float height;
public:
	Triangle(float base, float height, Point2D position, unsigned int RGBA);
	~Triangle();
	void render(SDL_Renderer *renderer);
	const float getBase();
	const float getHeight();
	void setBase(float base);
	void setHeight(float height);
};

