#pragma once
#include "Framework.h"
#include "Vertex.h"
#include "Matrix.h"
#include "Model.h"
#include "MD2Loader.h"

class Rasteriser : public Framework
{
public:	
	bool Initialise();
	
	void Render(const Bitmap &bitmap);
	void Update(const Bitmap &bitmap);

	void GeneratePerspectiveMatrix(float d, float aspectRatio);
	void GenerateViewMatrix(float d, int width, int height);
	
	void DrawWireFrame(const Bitmap &bitmap);

private:
	Matrix _transformmatrix;
	Matrix _modeltransformation;
	Matrix _perspectivetransformantion;
	Matrix _screentransformation;

	Vertex vertices[4];
	void DrawSquare(HDC hdc, Vertex vertices[]);
	Model _model;
	Camera _camera;

	
	Matrix PerspectiveTransformation;
	Matrix ScreenTransformation;

	float xangle = 0;
	float yangle = 0;
	float zangle = 0;

	float _x;
	float _y;
};

