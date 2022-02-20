#pragma once

// Class representing a 2D vertex (i.e a point in two dimensional space)

class Vertex
{
public:
	Vertex(void);
	Vertex(float x, float y, float z); 
	Vertex(const Vertex& v);
	Vertex(Vertex&& other);



	~Vertex(void);

	float GetX(void) const;
	void SetX(float x);
	float GetY(void) const;
	void SetY(float y);
	float GetW(void) const;
	void SetW(float w);
	float GetZ(void) const;
	void SetZ(float z);

	void Dehomogenize();

	

	Vertex& operator= (const Vertex& rhs);
	Vertex& operator= (Vertex&& rhs);

private:
	float _x;
	float _y;
	float _w;
	float _z;
	

	void Init(float x, float y, float z);
	void Copy(const Vertex& v);
};

