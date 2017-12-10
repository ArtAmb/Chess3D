#include "RGB.h"

Colors::RGB::RGB(int r, int b, int g, int a)
{
    this->r = r;
    this->g = g;
    this->b = b;
	this->a = a;
}

int Colors::RGB::toColorValue(){
	return 0;
}

Colors::RGB::~RGB()
{
    //dtor
}
