/**
 * Courtesy: Kevin Suffern
*/

#include "Parallel.hpp"

Parallel::Parallel()
{
    this->dir = Vector3D(0, 0, -1);
}

Parallel::Parallel(float c)
{
    Vector3D v(c);
    v.normalize();
    this->dir = v;
}

Parallel::Parallel(float x, float y, float z)
{
    Vector3D v(x, y, z);
    v.normalize();
    this->dir = v;
}

Parallel::Parallel(const Vector3D &d)
{
    Vector3D v(d);
    v.normalize();
    this->dir = v;
}

Parallel::Parallel(const Parallel &camera)
{
    this->dir = camera.dir;
}

Parallel &Parallel::operator=(const Parallel &other)
{
    if (this == &other)
        return (*this);

    dir = other.dir;

    return (*this);
}

Vector3D Parallel::get_direction(const Point3D &p) const
{
    (void)p; // parallel camera has the same dir
    return dir;
}
