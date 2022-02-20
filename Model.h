#pragma once

#include <vector>
#include "Polygon3D.h"
#include "Matrix.h"
#include "Camera.h"
#include <cmath>
#include <algorithm>
#include "Vector3D.h"



using namespace std;

class Model
{
	public:
		Model();
		~Model();
		// Accessors
		const vector<Polygon3D> GetPolygons();
		const vector<Vertex>& GetVertices();
		vector<Vertex> GetTransformedVertices();
		size_t GetPolygonCount() const;
		size_t GetVertexCount() const;
		void AddVertex(float x, float y, float z);	
		void AddPolygon(int i0, int i1, int i2);

		//applies the transformation matrix to each vertex in the original collection.
		void ApplyTransformToLocalVertices(const Matrix& transform);
		//applies the transfomation matrix to each vertex in the transformed vertices collection.
		void ApplyTransformToTransformedVertices(const Matrix& transform);

		void DehomogenizeTransformedVertices(); 

		void CalculateBackfaces();

	private:

		//collection for the polygons loaded from the MD2 file
		vector<Polygon3D> _polygons;

		//collection for the vertices loaded from the MD2 file  - starting point
		vector<Vertex> _vertices;

		//collection of transformed vertices
		vector<Vertex> _transformedvertices; 
		
		Camera cameraobj;
		Matrix perspectiveMatrix;
};

