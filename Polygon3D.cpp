#include "Polygon3D.h"

Polygon3D::Polygon3D() : _indices{ 0 }
{

}

Polygon3D::Polygon3D(int index1, int index2, int index3)
{
	_indices[0] = index1;
	_indices[1] = index2;
	_indices[2] = index3;
}

Polygon3D::~Polygon3D()
{
}

Polygon3D::Polygon3D(const Polygon3D& p)
{
	Copy(p);
}


int Polygon3D::GetIndex(int vertex) const
{
	return _indices[vertex];
}

// Copy assignment operator
Polygon3D& Polygon3D::operator= (const Polygon3D& rhs)
{
	if (this != &rhs)
	{
		Copy(rhs);
	}
	return *this;
}




void Polygon3D::Copy(const Polygon3D& p)
{
	for (int i = 0; i < 3; i++)
	{
		_indices[i] = p.GetIndex(i);
	}
}