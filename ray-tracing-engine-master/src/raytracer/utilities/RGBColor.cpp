#include <sstream>
#include <string>
#include <cmath>

#include "RGBColor.hpp"

RGBColor::RGBColor()
{
  /*
    Constructor: Sets the r, g, b values to 0
  */

  this->r = 0.0;
  this->g = 0.0;
  this->b = 0.0;
}

RGBColor::RGBColor(float c)
{
  /*
    Constructor: Sets the r, g, b values
  */

  this->r = c;
  this->g = c;
  this->b = c;
}

RGBColor::RGBColor(float _r, float _g, float _b)
{
  /*
    Constructor: Sets the r, g, b values
  */

  this->r = _r;
  this->g = _g;
  this->b = _b;
}

std::string RGBColor::to_string() const
{
  /*
    String representation of a RGBColor

    @return [RGBColor] String representation of a RGBColor
  */

  std::stringstream ss_r(std::stringstream::in | std::stringstream::out);
  ss_r << r;
  std::string t_r = ss_r.str();

  std::stringstream ss_g(std::stringstream::in | std::stringstream::out);
  ss_g << g;
  std::string t_g = ss_g.str();

  std::stringstream ss_b(std::stringstream::in | std::stringstream::out);
  ss_b << b;
  std::string t_b = ss_b.str();

  return "(" + t_r + ", " + t_g + ", " + t_b + ")";
}

RGBColor RGBColor::operator+(const RGBColor &c) const
{
  /*
    Operator overload: Addition
  */

  return (RGBColor(r + c.r, g + c.g, b + c.b));
}

// compound addition.
RGBColor &RGBColor::operator+=(const RGBColor &c)
{
  /*
    Operator overload: Compound addition
  */

  r += c.r;
  g += c.g;
  b += c.b;

  return (*this);
}

RGBColor RGBColor::operator*(const float a) const
{
  /*
    Operator overload: Multiplication by a float
  */

  return (RGBColor(r * a, g * a, b * a));
}

RGBColor &RGBColor::operator*=(const float a)
{
  /*
    Operator overload: Compound multiplication by a float
  */

  r *= a;
  g *= a;
  b *= a;

  return (*this);
}

RGBColor RGBColor::operator/(const float a) const
{
  /*
    Operator overload: Division by a float
  */

  return (RGBColor(r / a, g / a, b / a));
}

RGBColor &RGBColor::operator/=(const float a)
{
  /*
    Operator overload: Compound division by a float
  */

  r /= a;
  g /= a;
  b /= a;

  return (*this);
}

RGBColor RGBColor::operator*(const RGBColor &c) const
{
  /*
    Operator overload: Component-wise multiplication
  */

  return (RGBColor(r * c.r, g * c.g, b * c.b));
}

bool RGBColor::operator==(const RGBColor &c) const
{
  /*
    Operator overload: Equality
  */

  return (r == c.r && g == c.g && b == c.b);
}

RGBColor RGBColor::powc(float p) const
{
  /*
    Operator overload: Raise components to a power
  */

  return (RGBColor(std::pow(r, p), std::pow(g, p), std::pow(b, p)));
}

float RGBColor::average(void) const
{
  /*
    Operator overload: Average of components
  */

  return (0.333333333333 * (r + g + b));
}

RGBColor operator*(const float a, const RGBColor &c)
{
  /*
    Operator overload: Multiplication by a float
  */

  return (c.r * a, c.g * a, c.b * a);
}