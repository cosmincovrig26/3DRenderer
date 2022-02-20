#pragma once
class Vector3D
{
public:
	Vector3D();

	Vector3D(float index1, float index2, float index3);

	float CalculateDotProduct(const Vector3D v1, const Vector3D v2);
	Vector3D CalculateCrossProduct(const Vector3D v1, const Vector3D v2);

	void SetIndex1(float index1);
	void SetIndex2(float index2);
	void SetIndex3(float index3);

	float GetX(void) const;
	float GetY(void) const;
	float GetZ(void) const;




private:

	float _indices[3];

};
