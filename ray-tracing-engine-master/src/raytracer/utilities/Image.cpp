#include <fstream>
#include <iostream>
#include <algorithm>

#include "Image.hpp"
#include "../world/ViewPlane.hpp"
#include "RGBColor.hpp"

Image::Image(int hres, int vres)
{
  /*
    Constructor: Sets the horizontal and vertical resolution

    @param [int] hres: Horizontal resolution
    @param [int] vres: Vertical resolution
  */

  this->hres = hres;
  this->vres = vres;
  this->colors = new RGBColor *[this->vres];

  for (size_t r = 0; r < this->hres; ++r)
  {
    this->colors[r] = new RGBColor[this->hres];
  }
}

Image::Image(const ViewPlane &vpane)
{
  /*
    Constructor: Sets the horizontal and vertical resolution using ViewPlane

    @param [ViewPlane] vpane: Any ViewPlane
  */

  this->hres = vpane.hres;
  this->vres = vpane.vres;
  this->colors = new RGBColor *[this->vres];

  for (int r = 0; r < hres; ++r)
  {
    this->colors[r] = new RGBColor[this->hres];
  }
}

Image::~Image()
{
  /*
    Destructor
  */

  for (int r = 0; r < this->hres; ++r)
  {
    delete[] this->colors[r];
  }
  delete[] this->colors;
}

void Image::set_pixel(int x, int y, const RGBColor &color)
{
  /*
    Sets the pixel color

    @param [int] x: Horizontal pixel component
    @param [int] y: Vertical pixel component
    @param [RGBColor] color: Color value of pixel
  */

  this->colors[y][x] = color;
}

void Image::write_ppm(std::string path) const
{
  /*
    Writes image to file in PPM format

    @param [std::string] path: Path of image to be saved

    c/o https://github.com/team-raytracer/raytracer
  */

  float max = 0;
  for (size_t r = 0; r < this->vres; ++r)
  {
    for (size_t c = 0; c < this->hres; ++c)
    {
      max = std::max(this->colors[r][c].r,
                     std::max(this->colors[r][c].g, std::max(this->colors[r][c].b, max)));
    }
  }

  std::ofstream file;
  file.open(path);

  file << "P3" << std::endl;                // indicates PPM type
  file << hres << " " << vres << std::endl; // width and height
  file << "255" << std::endl;               // maximum value for each chanel

  double scale = 255 / max;
  for (size_t r = 0; r < vres; ++r)
  {
    for (size_t c = 0; c < hres; ++c)
    {
      file << static_cast<int>(colors[r][c].r * scale) << " "
           << static_cast<int>(colors[r][c].g * scale) << " "
           << static_cast<int>(colors[r][c].b * scale) << "  ";
    }
    file << std::endl;
  }
  file.close();
}
