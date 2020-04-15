#include "../utilities/Constants.hpp"
#include "Sampler.hpp"

Sampler::Sampler()
{
        /*
                Constructor

                c/o Kevin Suffern
        */

        this->camera_ptr = NULL;
        this->viewplane_ptr = NULL;
}

Sampler::Sampler(Camera *c_ptr, ViewPlane *v_ptr)
{
        /*
                Constructor

                c/o Kevin Suffern
        */

        this->camera_ptr = c_ptr;
        this->viewplane_ptr = v_ptr;
}
