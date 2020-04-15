#include "Cosine.hpp"
#include "../utilities/ShadeInfo.hpp"

Cosine::Cosine()
{
	/*
		Constructor: Sets the color to (0, 0, 0)
	*/

	this->color = RGBColor(0);
}

Cosine::Cosine(float c)
{
	/*
		Constructor: Sets the color to (c, c, c)
	*/

	this->color = RGBColor(c);
}

Cosine::Cosine(float r, float g, float b)
{
	/*
		Constructor: Sets the color to (r, g, b)
	*/

	this->color = RGBColor(r, g, b);
}

Cosine::Cosine(const RGBColor &c)
{
	/*
		Constructor: Sets the color to another color
	*/

	this->color = c;
}

Cosine::Cosine(const Cosine &other)
{
	/*
		Copy constructor
	*/

	this->color = other.color;
}

Cosine &Cosine::operator=(const Cosine &other)
{
	/*
		Operator overload: Overloads the '=' operator
	*/

	if (this == &other)
		return (*this);

	Cosine::operator=(other);

	color = other.color;
	return (*this);
}

RGBColor Cosine::shade(const ShadeInfo &sinfo) const
{
	/*
		Calculates the RGBColor based on the shading information

		@param [ShadeInfo] sinfo: Shading information
		@return [RGBColor] The color value of pixel
	*/

	return this->color * (sinfo.normal * -sinfo.ray.d);
}
