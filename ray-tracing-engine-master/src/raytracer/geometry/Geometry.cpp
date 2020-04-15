#include "../materials/Material.hpp"
#include "Geometry.hpp"

Geometry::Geometry()
{
  this->material_ptr = NULL;
}

void Geometry::set_material(Material *mPtr)
{
  /*
    @param [Material] mPtr: Any material object
  */

  if (this->material_ptr != nullptr)
  {
    delete this->material_ptr;
  }

  this->material_ptr = mPtr;
}

Material *Geometry::get_material() const
{
  /*
    @return [Material] Pointer to material object
  */

  return material_ptr;
}
