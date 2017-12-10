#include "Rectangle3D.h"

Rectangle3D::Rectangle3D()
{
}


Rectangle3D::~Rectangle3D()
{
}

Rectangle3D::Rectangle3D(Point3D point, float length, float width, float heigth) {
	this->startPoint = point;
	this->length = length;
	this->width = width;
	this->height = height;
}


Point3D Rectangle3D::getL1_LB_C_Point() {
	return startPoint.move(0, 0, 0);
}
Point3D Rectangle3D::getL1_LT_C_Point() {
	return startPoint.move(0, length, 0);
}
Point3D Rectangle3D::getL1_RB_C_Point() {
	return startPoint.move(width, 0, 0);
}
Point3D Rectangle3D::getL1_RT_C_Point() {
	return startPoint.move(width, length, 0);
}


Point3D Rectangle3D::getL2_LB_C_Point() {
	return startPoint.move(0, 0, height);
}
Point3D Rectangle3D::getL2_LT_C_Point() {
	return startPoint.move(0, length, height);
}
Point3D Rectangle3D::getL2_RB_C_Point() {
	return startPoint.move(width, 0, height);
}
Point3D Rectangle3D::getL2_RT_C_Point() {
	return startPoint.move(width, length, height);
}