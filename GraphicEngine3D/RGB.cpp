#include "RGB.h"

Colors::RGB::RGB(float r, float b, float g, float a)
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
