#include "RGB.h"

Colors::RGB::RGB(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
	this->a = a;
}

float Colors::RGB::toColorValue(){
	return 0;
}

Colors::RGB::~RGB()
{
    //dtor
}
