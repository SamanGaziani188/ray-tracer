#include "ViewPlane.hpp"

ViewPlane::ViewPlane()
{
    /*
        Constructor
    */

    this->top_left = Point3D(-320, 240, 0);
    this->bottom_right = Point3D(320, -240, 0);
    this->normal = Vector3D(-320, 240, 0) ^ Vector3D(320, -240, 0);
    this->hres = 640;
    this->vres = 240;
}

int ViewPlane::get_hres() const
{
    /*
        @return [int] Horizontal resolution
    */

    return this->hres;
}

void ViewPlane::set_hres(int number)
{
    /*
        @param [int] number: Horizontal resolution
    */

    this->hres = number;
}

int ViewPlane::get_vres() const
{
    /*
        @return [int] Vertical resolution
    */

    return this->vres;
}

void ViewPlane::set_vres(int number)
{
    /*
        @param [int] number: Vertical resolution
    */

    this->vres = number;
}
