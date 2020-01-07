#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape(Point2D position, unsigned int RGBA)
{
	this->position = position;
	this->RGBA = RGBA;
}


Shape::~Shape()
{
}

const Point2D Shape::getPos() {
	return this->position;
}
void Shape::setPos(Point2D newPos) {
	this->position = newPos;
}
const unsigned int Shape::getRGBA() {
	return this->RGBA;
}
void Shape::setRGBA(unsigned int newRGBA) {
	if (newRGBA > 0xffffffff) {
		cout << "Value too large" << endl;
		return;
	}
	else if (newRGBA < 0) {
		cout << "Value too small" << endl;
		return;
	}
	this->RGBA = newRGBA;
}