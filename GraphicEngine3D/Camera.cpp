#include "Camera.h"
#include "glut.h"


Camera::Camera()
{
}

Camera::Camera(Point3D cameraPosition, Point3D placeCameraLookingAt, Point3D cameraVerticalOffset) {
	this->cameraPosition = cameraPosition;
	this->placeCameraLookingAt = placeCameraLookingAt;
	this->cameraVerticalOffset = cameraVerticalOffset;
}

Camera::~Camera()
{
}

void Camera::lookAt()
{			//	std::cout << cameraPosition.toString() << ", " << placeCameraLookingAt.toString() << ", " << cameraVerticalOffset.toString() << std::endl;
	gluLookAt(cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ(),
		placeCameraLookingAt.getX(), placeCameraLookingAt.getY(), placeCameraLookingAt.getZ(),
		cameraVerticalOffset.getX(), cameraVerticalOffset.getY(), cameraVerticalOffset.getZ());
}

void Camera::lookAtWithOffset(Point3D cameraPositionOff, Point3D placeCameraLookingAtOff, Point3D cameraVerticalOffsetOff) {
	lookAt(cameraPosition.move(cameraPositionOff), placeCameraLookingAt.move(placeCameraLookingAtOff), cameraVerticalOffset.move(cameraVerticalOffsetOff));
}


void Camera::lookAt(Point3D cameraPosition, Point3D placeCameraLookingAt, Point3D cameraVerticalOffset)
{
	gluLookAt(cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ(),
		placeCameraLookingAt.getX(), placeCameraLookingAt.getY(), placeCameraLookingAt.getZ(),
		cameraVerticalOffset.getX(), cameraVerticalOffset.getY(), cameraVerticalOffset.getZ());
}