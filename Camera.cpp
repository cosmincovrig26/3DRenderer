#include "Camera.h"

Camera::Camera()
{
	_xRotation = 0;
	_yRotation = 0;
	_zRotation = 0;
	_position = { 0,0,-50 };
}


Camera::Camera(float xRotation, float yRotation, float zRotation, const Vertex& position)
{
	_xRotation = 0;
	_yRotation = 0;
	_zRotation = 0;
	_position = { 0,0,-50 };

}


void Camera::SetxRotation(float xRotation)
{
	_xRotation = xRotation;
}


void Camera::SetyRotation(float yRotation)
{
	_yRotation = yRotation;
}


void Camera::SetzRotation(float zRotation)
{
	_zRotation = zRotation;
}


void Camera::SetPosition(const Vertex& position)
{
	Vertex _position = position;
}


Matrix Camera::GetMatrix()
{
	Matrix position{ 1, 0, 0, -_position.GetX(),
					 0, 1, 0, -_position.GetY(),
					 0, 0, 1, -_position.GetZ(),
					 0, 0, 0, 1 };

	Matrix _xRotationMatrix = { 1, 0, 0, 0,
							0, (float)cos(_xRotation), (float)sin(_xRotation), 0,
							0, (float)-sin(_xRotation), 1, 0,
								0, 0, 0, 1 };
	Matrix _yRotationMatrix = { (float)cos(_yRotation), 0, (float)-sin(_yRotation), 0,
							   0, 1, 0, 0,
							   (float)sin(0), 0, (float)cos(0), 0,
							   0, 0, 0, 1 };
	Matrix _zRotationMatrix =  { (float)cos(0), (float)sin(0), 0, 0,
							   (float)-sin(0), (float)cos(0), 0, 0,
							   0, 0, 1, 0,
							   0, 0, 0, 1 };
	Matrix viewingMatrix = _xRotationMatrix * _yRotationMatrix * _zRotationMatrix * position;
	
	return viewingMatrix;	
}





