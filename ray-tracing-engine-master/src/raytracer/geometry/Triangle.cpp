#include <algorithm>

#include "Triangle.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/BBox.hpp"

Triangle::Triangle()
{
	this->v0 = Point3D();
	this->v1 = Point3D();
	this->v2 = Point3D();
}

Triangle::Triangle(const Point3D &a, const Point3D &b, const Point3D &c)
{
	this->v0 = a;
	this->v1 = b;
	this->v2 = c;
}

Triangle::Triangle(const Triangle &object)
{
	this->v0 = object.v0;
	this->v1 = object.v1;
	this->v2 = object.v2;
}

Triangle &Triangle::operator=(const Triangle &rhs)
{
	if (this == &rhs)
		return (*this);

	Geometry::operator=(rhs);

	this->v0 = rhs.v0;
	this->v1 = rhs.v1;
	this->v2 = rhs.v2;
	return (*this);
}

BBox Triangle::getBBox(void) const
{
	/*
		Computes the bounding box for triangle
	*/

	Point3D globalmax = max(max(v0, v1), v2);
	Point3D globalmin = min(min(v0, v1), v2);

	return BBox(globalmin, globalmax);
}

std::string Triangle::to_string() const
{
	return "(" + v0.to_string() + ", " + v1.to_string() + ", " + v2.to_string() + ")";
}

bool Triangle::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
	/*
        Checks if ray hits the triangle

        @param [Ray] ray: Any ray from the pixel
        @param [float] t: Time reference at which ray-point intersection happens (if any)
        @param [ShadeInfo] s: Shading information
    */

	float a = v0.x - v1.x, b = v0.x - v2.x, c = ray.d.x, d = v0.x - ray.o.x;
	float e = v0.y - v1.y, f = v0.y - v2.y, g = ray.d.y, h = v0.y - ray.o.y;
	float i = v0.z - v1.z, j = v0.z - v2.z, k = ray.d.z, l = v0.z - ray.o.z;

	double m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
	double q = g * i - e * k, ss = e * j - f * i;

	float inv_denom = 1.0 / (a * m + b * q + c * ss);

	double e1 = d * m - b * n - c * p;
	double beta = e1 * inv_denom;

	if (beta < 0.0)
	{
		return (false);
	}

	double r = r = e * l - h * i;
	double e2 = a * n + d * q + c * r;
	double gamma = e2 * inv_denom;

	if (gamma < 0.0)
	{
		return (false);
	}

	if (beta + gamma > 1.0)
	{
		return (false);
	}

	double e3 = a * p - b * r + d * ss;
	double _t = e3 * inv_denom;

	if (_t < kEpsilon)
	{
		return (false);
	}

	t = _t;

	s.hit_point = ray.o + (t * ray.d);
	s.normal = (v1 - v0) ^ (v2 - v0);
	s.normal.normalize();

	return (true);
}
