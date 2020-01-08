#pragma once
#include "SDL.h"
#include "Shape.h"

class Rectangle:public Shape
{
	float width;
	float height;
public:
	Rectangle(float width, float height, Point2D position, unsigned int RGBA);
	~Rectangle();
	void render(SDL_Renderer *renderer);
	const float getWidth();
	const float getHeight();
	void setWidth(float width);
	void setHeight(float height);
};

