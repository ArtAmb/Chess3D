#include <iostream>
#include "Engine3D.h"
#include "Rectangle3D.h"
#include "GlutHeader.h"
Rectangle3D::Rectangle3D()
{
}


Rectangle3D::~Rectangle3D()
{
}

Rectangle3D::Rectangle3D(Point3D point, float length, float width, float height) {
	this->startPoint = point;
	this->length = length;
	this->width = width;
	this->height = height;
}


void Rectangle3D::drawTOP(Colors::RGB color) {
	Engine3DLoader::getEngine()
		->glColor3c(color)
		->glVertex3p(getL1_RT_C_Point())
		->glVertex3p(getL1_LT_C_Point())
		->glVertex3p(getL1_LB_C_Point())
		->glVertex3p(getL1_RB_C_Point());
}

void Rectangle3D::drawBOTTOM(Colors::RGB color) {
	Engine3DLoader::getEngine()
		->glColor3c(color)
		->glVertex3p(getL2_RT_C_Point())
		->glVertex3p(getL2_LT_C_Point())
		->glVertex3p(getL2_LB_C_Point())
		->glVertex3p(getL2_RB_C_Point());
}

void Rectangle3D::drawFRONT(Colors::RGB color) {
	Engine3DLoader::getEngine()
		->glColor3c(color)
		->glVertex3p(getL1_LT_C_Point())
		->glVertex3p(getL1_RT_C_Point())
		->glVertex3p(getL2_RT_C_Point())
		->glVertex3p(getL2_LT_C_Point());
}

void Rectangle3D::drawRIGHT(Colors::RGB color) {
	Engine3DLoader::getEngine()
		->glColor3c(color)
		->glVertex3p(getL2_RT_C_Point())
		->glVertex3p(getL1_RT_C_Point())
		->glVertex3p(getL1_RB_C_Point())
		->glVertex3p(getL2_RB_C_Point());
}

void Rectangle3D::drawLEFT(Colors::RGB color) {
	Engine3DLoader::getEngine()
		->glColor3c(color)
		->glVertex3p(getL2_LT_C_Point())
		->glVertex3p(getL1_LT_C_Point())
		->glVertex3p(getL1_LB_C_Point())
		->glVertex3p(getL2_LB_C_Point());
}

void Rectangle3D::drawBACK(Colors::RGB color) {
	Engine3DLoader::getEngine()
		->glColor3c(color)
		->glVertex3p(getL1_LB_C_Point())
		->glVertex3p(getL1_RB_C_Point())
		->glVertex3p(getL2_RB_C_Point())
		->glVertex3p(getL2_LB_C_Point());
}


void Rectangle3D::draw(Colors::RGB color){
	drawTOP(color);
	drawBOTTOM(color);
	drawFRONT(color);
	drawBACK(color);
	drawLEFT(color);
	drawRIGHT(color);
}

void Rectangle3D::draw(Colors::RGB color, Colors::RGB topColor) {
	drawTOP(topColor);
	drawBOTTOM(color);
	drawFRONT(color);
	drawBACK(color);
	drawLEFT(color);
	drawRIGHT(color);
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

void Rectangle3D::translateToTopCenterOfTopField(Point3D currentPosition) {
	/*std::cout << getL1_RT_C_Point().toString() << std::endl;
	std::cout << getL1_LT_C_Point().toString() << std::endl;
	std::cout << getL1_LB_C_Point().toString() << std::endl;
	std::cout << getL1_RB_C_Point().toString() << std::endl;*/

	Point3D verticalPoint = getL1_RT_C_Point().getMiddlePointFromMeTo(getL1_LT_C_Point());
	Point3D horizontalPoint = getL1_LT_C_Point().getMiddlePointFromMeTo(getL1_LB_C_Point());

	//glVertex3fv(verticalPoint.toVector());
	//glVertex3fv(horizontalPoint.toVector());
	Point3D newPossition(verticalPoint.getX(), horizontalPoint.getY(), getL1_LT_C_Point().getZ());
	
	glTranslatef(-(currentPosition.getX() - newPossition.getX()), -(currentPosition.getY() - newPossition.getY()), -(currentPosition.getZ() - newPossition.getZ()));
	//glTranslatef(2, 2, -1);
}