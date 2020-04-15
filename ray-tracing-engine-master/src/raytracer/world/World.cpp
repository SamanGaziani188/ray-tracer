#include <iostream>

#include "../utilities/BBox.hpp"
#include "../geometry/Geometry.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "World.hpp"

World::World()
{
    /*
        Constructor
    */

    this->camera_ptr = NULL;
    this->sampler_ptr = NULL;
    this->bg_color = 0;
}

World::~World()
{
    /*
        Destructor
    */

    this->camera_ptr = NULL;
    this->sampler_ptr = NULL;
    this->geometry.clear();
}

void World::add_geometry(Geometry* geom_ptr)
{
    /*
        Adds a new geometry to the vector

        @param [Geometry] geom_ptr: Any geometry
    */

    this->geometry.push_back(geom_ptr);
}

void World::set_camera(Camera* c_ptr)
{
    /*
        Sets the camera

        @param [Camera] c_ptr: Any camera
    */

    this->camera_ptr = c_ptr;
}

ShadeInfo World::hit_objects(const Ray& ray)
{
    /*
        Checks if the ray intersects any of the objects in the vector and then computes the cumulative shading information

        @param [Ray] ray: Ray from the pixel
    */

    ShadeInfo shadeInfo(*this);
    ShadeInfo shadeInfoMin(*this);
    float t;
    float tmin = kHugeValue;

    for (int i = 0; i < geometry.size(); i++)
    {
        if (geometry[i]->hit(ray, t, shadeInfo) && (t < tmin)){
            tmin = t;

            shadeInfoMin = shadeInfo;
            shadeInfoMin.hit = true;
            shadeInfoMin.material_ptr = geometry[i]->get_material();
            shadeInfoMin.ray = ray;
            shadeInfoMin.t = t;
        }
    }
    return shadeInfoMin;
}
