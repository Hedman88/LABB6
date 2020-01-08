#pragma once
#include "SDL.h"
#include "FilledTriangle.h"
class TriangleOutline:public FilledTriangle
{
	float base;
	float height;
public:
	TriangleOutline(float base, float height, Point2D position);
	~TriangleOutline();
	void render(SDL_Renderer *renderer);
};

