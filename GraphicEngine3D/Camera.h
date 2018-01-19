#pragma once
#include "Point3D.h"
class Camera
{
	Point3D cameraPosition;
	Point3D placeCameraLookingAt;
	Point3D cameraVerticalOffset;

	Point3D startCameraPosition;
	Point3D startPlaceCameraLookingAt; 
	Point3D startCameraVerticalOffset;
public:
	Camera();
	Camera(Point3D cameraPosition, Point3D placeCameraLookingAt, Point3D cameraVerticalOffset);
	~Camera();

	Point3D* getPosition() {
		return &cameraPosition;
	}

	Point3D* getPlaceCameraLookingAt()
	{
		return &placeCameraLookingAt;
	}

	Point3D* getVerticalOffset() {
		return &cameraVerticalOffset;
	}

	void lookAt();
	void lookAt(Point3D cameraPosition, Point3D placeCameraLookingAt, Point3D cameraVerticalOffset);
	void lookAtWithOffset(Point3D cameraPositionOff, Point3D placeCameraLookingAtOff, Point3D cameraVerticalOffsetOff);
	void reset();
};

