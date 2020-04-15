/**
 * Courtesy: Kevin Suffern
*/

#include <iostream>
#include <vector>

#include "Simple.hpp"
#include "../cameras/Camera.hpp"
#include "../utilities/Ray.hpp"
#include "../world/ViewPlane.hpp"

Simple::Simple(Camera *c_ptr, ViewPlane *v_ptr) : Sampler(c_ptr, v_ptr) {}

Simple::Simple(const Simple &camera) : Sampler(camera.camera_ptr, camera.viewplane_ptr) {}

Simple &Simple::operator=(const Simple &other)
{
  /*
    Copy constructor
  */

  if (this == &other)
    return (*this);

  camera_ptr = other.camera_ptr;
  viewplane_ptr = other.viewplane_ptr;

  return (*this);
}

std::vector<Ray> Simple::get_rays(int px, int py) const
{
  /*
    Computes the rays out of given pixel location
  */

  std::vector<Ray> allRays;
  Ray ray;
  Point3D origin;
  Vector3D diff = viewplane_ptr->bottom_right - viewplane_ptr->top_left;

  double divX = (double)px / (double)(viewplane_ptr->hres);
  double divY = (double)py / (double)(viewplane_ptr->vres);

  origin = viewplane_ptr->top_left + Vector3D(divX * diff.x, divY * diff.y, 0);
  ray.o = origin;
  ray.d = camera_ptr->get_direction(origin);
  ray.d.normalize();

  allRays.push_back(ray);
  return allRays;
}
