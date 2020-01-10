#pragma once
#include "Point2D.h"
#include "SDL.h"
class Shape
{
protected:
	Point2D position;
	unsigned int RGBA = 00000000;
public:
	Shape();
	Shape(Point2D position, unsigned int RGBA);
	~Shape();
	virtual void render(SDL_Renderer *renderer) = 0;
	const Point2D getPos();
	void setPos(Point2D newPos);
	const unsigned int getRGBA();
	void setRGBA(unsigned int newRGBA);
	virtual bool hitbox(int mouseX, int mouseY) = 0;
};

