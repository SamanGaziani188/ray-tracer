#include <cmath>
#include <sstream>
#include <string>#include <math.h>
#include "Point3D.hpp"
#include "Vector3D.hpp"

Point3D::Point3D()
{
	/*
        Constructor: Sets point to (0, 0, 0)
    */

	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Point3D::Point3D(float c)
{
	/*
        Constructor: Sets point to (c, c, c)

        @param [float] c: The component of point along a each axis
    */

	this->x = c;
	this->y = c;
	this->z = c;
}

Point3D::Point3D(float x, float y, float z)
{
	/*
        Constructor: Sets point to (x,y,z)

        @param [float] x: The component of point along a x axis
        @param [float] y: The component of point along a y axis
        @param [float] z: The component of point along a z axis
    */

	this->x = x;
	this->y = y;
	this->z = z;
}

std::string Point3D::to_string() const
{
	/*
        Converts the point into its string representation

        @return [std::string]: Point's string representation
    */

    std::stringstream ss_x (std::stringstream::in | std::stringstream::out);
    ss_x << x;
    std::string tX = ss_x.str();

    std::stringstream ss_y (std::stringstream::in | std::stringstream::out);
    ss_y << y;
    std::string tY = ss_y.str();

    std::stringstream ss_z (std::stringstream::in | std::stringstream::out);
    ss_z << z;
    std::string tZ = ss_z.str();

	return "(" + tX + ", " + tY + ", " + tZ + ")";
}

Point3D Point3D::operator-() const
{
	/*
        Operator overload: Overloads the '-' operator for unary operation

        @return [Point3D]: New point
    */

	return (Point3D(-this->x, -this->y, -this->z));
}

Vector3D Point3D::operator-(const Point3D &p) const
{
	/*
        Operator overload: Overloads the '-' operator for vector joining two points

        @param [Point3D] p: Any other point
        @return [Vector3D]: New vector represented by two points
    */

	return (Vector3D(this->x - p.x, this->y - p.y, this->z - p.z));
}

Point3D Point3D::operator+(const Vector3D &v) const
{
	/*
        Operator overload: Overloads the '+' operator for addition of vector to a point

        @param [Vector3D] v: Any other vector
        @return [Point3D]: New point after addition
    */

	return (Point3D(this->x + v.x, this->y + v.y, this->z + v.z));
}

Point3D Point3D::operator-(const Vector3D &v) const
{
	/*
        Operator overload: Overloads the '-' operator for subtraction of vector from a point

        @param [Vector3D] v: Any other vector
        @return [Point3D]: New point after subtraction
    */

	return (Point3D(this->x - v.x, this->y - v.y, this->z - v.z));
}

Point3D Point3D::operator*(const float s) const
{
	/*
        Operator overload: Overloads the '*' operator for scaling the point by a factor

        @param [float] s: Scaling factor
        @return [Point3D]: New point after scaling
    */

	return (Point3D(this->x * s, this->y * s, this->z * s));
}

float Point3D::d_squared(const Point3D &p) const
{
	/*
        Calculates the square of the distance between the two points

        @param [Point3D] p: Any other point
        @return [float]: Square of the distance
    */
    return ((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y) + (this->z - p.z) * (this->z - p.z));
}

float Point3D::distance(const Point3D &p) const
{
	/*
        Calculates the distance between the two points

        @param [Point3D] p: Any other point
        @return [float]: The distance
    */

    return std::sqrt(this->d_squared(p));
}

Point3D operator*(const float a, const Point3D &pt)
{
	/*
        Operator overload: Overloads the '*' operator for scaling any point by a factor

        @param [float] a: Scaling factor
        @param [Point3D] pt: Any other point
        @return [Point3D]: New point after scaling
    */

	return (Point3D(pt.x * a, pt.y * a, pt.z * a));
}

Point3D min(const Point3D& a, const Point3D& b)
{
	/*
        Finds the min point between two points

        @param [Point3D] a: Any other point
        @param [Point3D] b: Any other point
        @return [Point3D]: min(a, b)
    */

	Point3D* point = new Point3D();
	if (a.x < b.x)
	{
		point->x = a.x;
	}
	else
	{
		point->x = b.x;
	}

	if (a.y < b.y)
	{
		point->y = a.y;
	}
	else
	{
		point->y = b.y;
	}

	if (a.z < b.z)
	{
		point->z = a.z;
	}
	else
	{
		point->z = b.z;
	}

	return *point;
}

Point3D max(const Point3D& a, const Point3D& b)
{
	/*
        Finds the max point between two points

        @param [Point3D] a: Any other point
        @param [Point3D] b: Any other point
        @return [Point3D]: max(a, b)
    */

	Point3D* point = new Point3D();
	if (b.x < a.x)
	{
		point->x = a.x;
	}
	else
	{
		point->x = b.x;
	}

	if (b.y < a.y)
	{
		point->y = a.y;
	}
	else
	{
		point->y = b.y;
	}

	if (b.z < a.z)
	{
		point->z = a.z;
	}
	else
	{
		point->z = b.z;
	}

	return *point;
}
