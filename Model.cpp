#include "Model.h"



//default constructor
Model::Model()
{

}

//Destructor
Model::~Model()
{
}






const vector<Polygon3D> Model::GetPolygons()
{
	return _polygons;
}

const vector<Vertex>& Model::GetVertices()
{
	return _vertices;
}

vector<Vertex> Model::GetTransformedVertices()
{
	return _transformedvertices;
}

size_t Model::GetPolygonCount() const
{
	return _polygons.size();
}

size_t Model::GetVertexCount() const
{
	return _vertices.size();
}

void Model::AddVertex(float x, float y, float z)
{
	_vertices.push_back({ x, y, z });
}

void Model::AddPolygon(int i0, int i1, int i2)
{
	_polygons.push_back({ i0, i1, i2 });
}


void Model::ApplyTransformToLocalVertices(const Matrix& transform)
{
	_transformedvertices.clear();
	for (int i = 0; i < _vertices.size(); i++)
	{
		_transformedvertices.push_back(transform * _vertices[i]);
	}
}

void Model::DehomogenizeTransformedVertices()
{
	for (int i = 0; i < _transformedvertices.size(); i++)
	{
		_transformedvertices[i].Dehomogenize();
	}
}

void Model::ApplyTransformToTransformedVertices(const Matrix& transform)
{
	vector<Vertex>_temptransform;

	for (int i = 0; i < _vertices.size(); i++)
	{
		_temptransform.push_back(transform * _transformedvertices[i]);
	}
	_transformedvertices = _temptransform;

}

void Model::CalculateBackfaces()
{



	for (int i = 0; i < _polygons.size(); i++)
	{
		Polygon3D _tempPolygon = GetPolygons()[i];

		Vertex First = GetVertices()[_tempPolygon.GetIndex(0)];
		Vertex Second = GetVertices()[_tempPolygon.GetIndex(1)];
		Vertex Third = GetVertices()[_tempPolygon.GetIndex(2)];



	}
}