#pragma once
#include <sstream>
#include <string>
class Point3D
{
	float x, y, z;
public:

	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }
	void setZ(float z) { this->z = z; }
	
	float getX() { return x; }
	float getY() { return y; }
	float getZ() { return z; }
	float* toVector();
	Point3D();
	Point3D(float x, float y, float z);
	~Point3D();

	Point3D move(float off_x, float off_y, float off_z);
	void moveMyself(float off_x, float off_y, float off_z);

	Point3D getMiddlePointFromMeTo(Point3D point) {
		return Point3D(average(x, point.getX()), average(y, point.getY()), average(z, point.getZ()));
	}

	float average(float a, float b) {
		return (a + b) / 2;
	}

	std::string toString();
};

