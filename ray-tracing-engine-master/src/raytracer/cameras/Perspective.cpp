/**
 * Courtesy: Kevin Suffern
*/

#include "Perspective.hpp"
#include "../utilities/Vector3D.hpp"

Perspective::Perspective(void)
{
	this->pos = Point3D();
}

Perspective::Perspective(float c)
{
	this->pos = Point3D(c);
}

Perspective::Perspective(float x, float y, float z)
{
	this->pos = Point3D(x,y,z);
}

Perspective::Perspective(const Point3D &pt)
{
	this->pos = pt;
}

Perspective::Perspective(const Perspective& camera)
{
	this->pos = camera.pos;
}

Perspective &Perspective::operator= (const Perspective& other) {
	if (this == &other)
		return (*this);

	pos			= other.pos;

	return (*this);
}

Vector3D
Perspective::get_direction(const Point3D &p) const
{
    Vector3D v(p - pos);
    v.normalize();
	return v;
}
