#pragma once
#include "SDL.h"
#include "Shape.h"

class FilledRectangle:public Shape
{
	float width;
	float height;
public:
	FilledRectangle();
	FilledRectangle(float width, float height, Point2D position, unsigned int RGBA);
	~FilledRectangle();
	void render(SDL_Renderer *renderer);
	const float getWidth();
	const float getHeight();
	void setWidth(float width);
	void setHeight(float height);
};

