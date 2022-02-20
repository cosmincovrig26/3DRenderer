#pragma once
class Polygon3D
{
public:	
	
	Polygon3D();
	Polygon3D(int index1, int index2, int index3);
	~Polygon3D();
	Polygon3D(const Polygon3D& p);

	// Accessor to return index of specified vertex
	int GetIndex(int vertex) const;

	
	Polygon3D& operator= (const Polygon3D& rhs);


private:

	int _indices[3];

	void Copy(const Polygon3D& p);
};

