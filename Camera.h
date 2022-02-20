#pragma once
#include <cmath>
#include "Matrix.h"
#include "Vertex.h"
class Camera
{
public:
	
	Camera();

	Camera(float xRotation, float yRotation, float zRotation, const Vertex& position);


	void SetxRotation(float xRotation);
	void SetyRotation(float yRotation);
	void SetzRotation(float zRotation);
	void SetPosition(const Vertex& position);
	Matrix GetMatrix();

private:
	
	
	
	float _xRotation;
	float _yRotation;
	float _zRotation;
	Vertex _position;
};

