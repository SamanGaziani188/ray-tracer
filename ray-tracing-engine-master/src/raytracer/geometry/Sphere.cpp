/**
 * Courtesy: Kevin Suffern
*/

#include <cmath>
#include <string>
#include <sstream>

#include "Sphere.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/BBox.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"

Sphere::Sphere()
{
	this->c = Point3D();
	this->r = 0;
}

Sphere::Sphere(const Point3D &center, float radius)
{
	this->c = center;
	this->r = radius;
}

Sphere::Sphere(const Sphere &object)
{
	this->c = object.c;
	this->r = object.r;
}

Sphere &Sphere::operator=(const Sphere &rhs)
{
	if (this == &rhs)
		return (*this);

	Geometry::operator=(rhs);

	c = rhs.c;
	r = rhs.r;

	return (*this);
}

BBox Sphere::getBBox() const
{
	/*
		Computes the BBox
	*/

	Vector3D offset = Vector3D(r);
	Point3D globalmin = c - offset;
	Point3D globalmax = c + offset;
	BBox bb(globalmin, globalmax);

	return bb;
}

std::string Sphere::to_string() const
{
	std::stringstream ss_r(std::stringstream::in | std::stringstream::out);

	ss_r << r;

	std::string t_r = ss_r.str();

	return "c:" + c.to_string() + ", r:" + t_r;
}

bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
	/*
        Checks if ray hits the sphere

        @param [Ray] ray: Any ray from the pixel
        @param [float] t: Time reference at which ray-point intersection happens (if any)
        @param [ShadeInfo] s: Shading information
    */

	Vector3D oc = ray.o - c;
	double _a = ray.d * ray.d;
	double _b = 2 * ray.d * oc;
	double _c = (oc * oc) - (r * r);
	double tmin;

	double discriminant = (_b * _b) - (4 * _a * _c);

	if (discriminant < 0)
	{
		return false;
	}
	else
	{
		double e = std::sqrt(discriminant);
		double denom = 2 * _a;
		tmin = (-_b - e) / denom;

		if (tmin > kEpsilon)
		{
			t = tmin;
			s.normal = (oc + t * ray.d) / r;
			s.hit_point = ray.o + (t * ray.d);
			s.normal.normalize();

			return true;
		}

		tmin = (-_b + e) / denom;
		if (t > kEpsilon)
		{
			t = tmin;
			s.normal = (oc + t * ray.d) / r;
			s.hit_point = ray.o + (t * ray.d);
			s.normal.normalize();

			return true;
		}
	}

	return false;
}