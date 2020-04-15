/**
 * Courtesy: Kevin Suffern
*/

#include "Plane.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../utilities/Ray.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/Vector3D.hpp"
#include "../utilities/BBox.hpp"

Plane::Plane()
{
    /*
        Constructor: Sets a=(0, 0, 0) and n=(0, 0, 1)
    */

    this->a = Point3D(0, 0, 0);
    this->n = Vector3D(0, 0, 1);
}

Plane::Plane(const Point3D &pt, const Vector3D &n)
{
    /*
        Constructor: Sets a and n
    */

    Vector3D v(n);
    v.normalize();

    this->n = v;
    this->a = pt;
}

Plane::Plane(const Plane &object)
{
    /*
        Copy constructor
    */

    this->n = object.n;
    this->a = object.a;
}

Plane &Plane::operator=(const Plane &rhs)
{
    /*
        Operator overloading: Overloads the '=' operator
    */

    if (this == &rhs)
        return (*this);

    Geometry::operator=(rhs);

    a = rhs.a;
    n = rhs.n;

    return (*this);
}

BBox Plane::getBBox() const
{
    BBox b;
    return b;
}

std::string Plane::to_string() const
{
    return "a:" + a.to_string() + ", n:" + n.to_string();
}

bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const
{
    /*
        Checks if ray hits the plane

        @param [Ray] ray: Any ray from the pixel
        @param [float] t: Time reference at which ray-point intersection happens (if any)
        @param [ShadeInfo] s: Shading information
    */

    float _t = ((a - ray.o) * n) / (ray.d * n);
    
    if (_t > kEpsilon)
    {
        // Update ShadeInfo
        t = _t;
        s.hit_point = ray.o + (t * ray.d);
        s.normal = n;
        s.normal.normalize();
        return true;
    }

    return false;
}
