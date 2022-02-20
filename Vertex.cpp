#include "Vertex.h"

// Constructors

Vertex::Vertex(void)
{
	Init(0.0f, 0.0f, 0.0f);
}

Vertex::Vertex(float x, float y, float z)
{
	Init(x, y, z);
}

Vertex::Vertex(const Vertex& v)
{
	Copy(v);
}

Vertex::Vertex(Vertex&& v)
{
	Copy(v);
}

Vertex::~Vertex(void)
{
}

// Accessors and mutators

float Vertex::GetX(void) const
{
	return _x;
}

void Vertex::SetX(float x)
{
	_x = x;
}

float Vertex::GetY(void) const
{
	return _y;
}

void Vertex::SetY(float y)
{
	_y = y;
}

float Vertex::GetW(void) const
{
	return _w;
}

void Vertex::SetW(float w)
{
	_w = w;
}

float Vertex::GetZ(void) const
{
	return _z;
}

void Vertex::SetZ(float z)
{
	_z = z;
}

// Operator overloads

Vertex& Vertex::operator= (const Vertex& rhs)
{
	if (this != &rhs)
	{
		// Only copy if we are not assigning to ourselves. 
		// (remember that a = b is the same as a.operator=(b))
		Copy(rhs);
	}
	return *this;
}

Vertex& Vertex::operator= (Vertex&& rhs)
{
	if (this != &rhs)
	{
		// Only copy if we are not assigning to ourselves. 
		// (remember that a = b is the same as a.operator=(b))
		Copy(rhs);
	}
	return *this;
}


// Private methods

void Vertex::Init(float x, float y, float z)
{
	_x = x;
	_y = y;
	_z = z;
	_w = 1;
}

void Vertex::Copy(const Vertex& v)
{
	_x = v.GetX();
	_y = v.GetY();
	_z = v.GetZ();
	_w = v.GetW();
}

void Vertex::Dehomogenize()
{
	_x = GetX() / GetW();
	_y = GetY() / GetW();
	_z = GetZ() / GetW();
	_w = 1;
}





