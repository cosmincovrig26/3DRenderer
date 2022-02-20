#include "Rasteriser.h"

Rasteriser app;

bool Rasteriser::Initialise()
{
	vertices[0] = Vertex(200, 200, 0);
	vertices[1] = Vertex(250, 200, 0);
	vertices[2] = Vertex(250, 250, 0);
	vertices[3] = Vertex(200, 250, 0);
	_x = 0.0f;
	_y = 1.0f;

	

	if (!MD2Loader::LoadModel("cube.md2", _model,
		&Model::AddPolygon,
		&Model::AddVertex))
	{
		return false;
	}

	return true;
}


void Rasteriser::Update(const Bitmap &bitmap)
{
	yangle += 0.01f;

	Matrix rotateX{ 1, 0, 0, 0,
					 0, (float)cos(xangle), -(float)sin(xangle), 0,
					 0, (float)sin(xangle), (float)cos(xangle), 0,
					 0, 0, 0, 1 };
	
	Matrix rotateY{ (float)cos(yangle), 0, (float)sin(yangle), 0,
					0, 1, 0, 0,
					-(float)sin(yangle), 0, (float)cos(yangle), 0,
					0, 0, 0, 1 };

	Matrix rotateZ{ (float)cos(zangle), -(float)sin(zangle), 0, 0,
					(float)sin(zangle), (float)cos(zangle), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1 };

	_transformmatrix = rotateX * rotateY * rotateZ;
	
	

	GeneratePerspectiveMatrix((float)1, ((float)bitmap.GetWidth() / (float)bitmap.GetHeight()));
	
	
	GenerateViewMatrix((float)1, bitmap.GetWidth(), bitmap.GetHeight());
}

void Rasteriser::Render(const Bitmap &bitmap)
{
	bitmap.Clear(RGB(255, 255,255));
	_model.ApplyTransformToLocalVertices(_transformmatrix);
	_model.ApplyTransformToTransformedVertices(_camera.GetMatrix());
	_model.ApplyTransformToTransformedVertices(_perspectivetransformantion);
	_model.DehomogenizeTransformedVertices();
	_model.ApplyTransformToTransformedVertices(_screentransformation);

	DrawWireFrame(bitmap);
}

void Rasteriser::GeneratePerspectiveMatrix(float d, float aspectRatio)
{
	Matrix PerspectiveMatrix{
		d / aspectRatio, 0, 0, 0,
		0, d, 0, 0,
		0, 0, d, 0,
		0, 0, 1, 0 };
	_perspectivetransformantion = PerspectiveMatrix;
}

void Rasteriser::GenerateViewMatrix(float d, int width, int height)
{
	Matrix ScreenMatrix{
		(float)width / 2, 0, 0, (float)width / 2,
		0, (float)-height / 2, 0, (float)height / 2,
		0, 0, d / 2, d / 2,
		0, 0, 0, 1 };
	_screentransformation = ScreenMatrix;
}

void Rasteriser::DrawWireFrame(const Bitmap& bitmap)
{
	
	
	for (int i = 0; i < _model.GetPolygonCount(); i++)
	{
		Polygon3D myObj = _model.GetPolygons()[i];
		
		Vertex first = _model.GetTransformedVertices()[myObj.GetIndex(0)];
		Vertex second = _model.GetTransformedVertices()[myObj.GetIndex(1)];
		Vertex third = _model.GetTransformedVertices()[myObj.GetIndex(2)];
		HDC hdc = bitmap.GetDC();
		MoveToEx(hdc, (int)first.GetX(), (int)first.GetY(), NULL);
		LineTo(hdc, (int)second.GetX(), (int)second.GetY());
		LineTo(hdc, (int)third.GetX(), (int)third.GetY());
		LineTo(hdc, (int)first.GetX(), (int)first.GetY());
	}
}