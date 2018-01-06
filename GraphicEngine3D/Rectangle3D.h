#pragma once
#include "Point3D.h"
#include "RGB.h"
class Rectangle3D
{
	Point3D startPoint;
	float length, width, height;

	void drawTOP(Colors::RGB color);
	void drawBOTTOM(Colors::RGB color);
	void drawFRONT(Colors::RGB color);
	void drawBACK(Colors::RGB color);
	void drawLEFT(Colors::RGB color);
	void drawRIGHT(Colors::RGB color);
public:
	Point3D getStartPoint() {
		return startPoint;
	}
	float getLength() {
		return length;
	}
	float getWidth() {
		return width;
	}
	float getHeight() {
		return height;
	}
	Rectangle3D();
	Rectangle3D(Point3D point, float length, float width, float heigth);
	~Rectangle3D();
		
	void draw(Colors::RGB color);

	Point3D getL1_LB_C_Point();
	Point3D getL1_LT_C_Point();
	Point3D getL1_RB_C_Point();
	Point3D getL1_RT_C_Point();


	Point3D getL2_LB_C_Point();
	Point3D getL2_LT_C_Point();
	Point3D getL2_RB_C_Point();
	Point3D getL2_RT_C_Point();
};

