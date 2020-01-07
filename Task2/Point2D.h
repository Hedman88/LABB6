#pragma once
#include <string>
class Point2D
{
	float x, y;
public:
	Point2D();
	Point2D(float x, float y);
	Point2D(const Point2D &o);
	~Point2D();
	float distance(const Point2D &o);
	std::string toString();
	Point2D operator+(const Point2D &o);
	Point2D &operator=(const Point2D &o);
	bool operator==(const Point2D &o);
	float getX();
	float getY();
};

