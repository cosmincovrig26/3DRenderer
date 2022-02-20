#include "Vector3D.h"

Vector3D::Vector3D() : _indices{ 0 }
{

}

Vector3D::Vector3D(float index1, float index2, float index3)
{
	_indices[0] = index1;
	_indices[1] = index2;
	_indices[2] = index3;
}


float Vector3D::CalculateDotProduct(const Vector3D v1, const Vector3D v2)
{
	float DotProduct = (v1.GetX() * v2.GetX()) + (v1.GetY() * v2.GetZ()) + (v1.GetZ() * v2.GetZ());
	return DotProduct;
}

Vector3D Vector3D::CalculateCrossProduct(const Vector3D v1, const Vector3D v2)
{
	Vector3D CrossProduct;
	CrossProduct.SetIndex1((v1.GetY() * v2.GetZ()) - (v1.GetZ() * v2.GetY()));
	CrossProduct.SetIndex2((v1.GetZ() * v2.GetX()) - (v1.GetX() * v2.GetZ()));
	CrossProduct.SetIndex3((v1.GetX() * v2.GetY()) - (v1.GetY() * v2.GetX()));

	return CrossProduct;
}



void Vector3D::SetIndex1(float index1)
{
	_indices[0] = index1;
}

void Vector3D::SetIndex2(float index2)
{
	_indices[1] = index2;
}

void Vector3D::SetIndex3(float index3)
{
	_indices[2] = index3;
}

float Vector3D::GetX(void) const
{
	return _indices[0];
}

float Vector3D::GetY(void) const
{
	return _indices[1];
}

float Vector3D::GetZ(void) const
{
	return _indices[2];
}



