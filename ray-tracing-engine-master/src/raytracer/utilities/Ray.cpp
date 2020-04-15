#include <sstream>
#include <string>

#include "Ray.hpp"

Ray::Ray()
{
  /*
    Constructor: Sets the origin=0, direction=0 and weight=1 of the ray
  */

  this->o = Point3D(0.0);
  this->d = Vector3D(0.0, 0.0, 1.0);
  this->w = 1.0;
}

Ray::Ray(const Point3D &origin, const Vector3D &dir)
{
  /*
    Constructor: Sets the origin, direction and weight=1 of the ray
  */

  this->o = origin;
  this->d = dir;
  this->w = 1.0;
}

std::string Ray::to_string() const
{
  /*
    String representation of a Ray

    @return [std::string] String representation of a Ray
  */

  std::stringstream ss_w(std::stringstream::in | std::stringstream::out);

  ss_w << w;

  std::string t_w = ss_w.str();
  return "(" + o.to_string() + ", " + d.to_string() + ", " + t_w + ")";
}