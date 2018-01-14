#include "Point3D.h"



Point3D::Point3D()
{
}


Point3D::~Point3D()
{
}

Point3D::Point3D(float x, float y, float z) {
	setX(x);
	setY(y);
	setZ(z);

}

float* Point3D::toVector() {
	float tmp[3] = { x,y,z };
	return tmp;
}

Point3D Point3D::move(float off_x, float off_y, float off_z) {
	return Point3D(x + off_x, y + off_y, z + off_z);
}

Point3D Point3D::move(Point3D offVector)
{
	return move(offVector.getX(), offVector.getY(), offVector.getZ());
}

void Point3D::moveMyself(float off_x, float off_y, float off_z) {
	x += off_x;
	y += off_y;
	z += off_z;
}


std::string Point3D::toString() {
	std::ostringstream result;
	result << "[" << x << ", " << y << ", " << z << "]";
	return result.str();
}