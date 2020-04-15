#include "ShadeInfo.hpp"

ShadeInfo::ShadeInfo(const World &wr)
{
	/*
		Constructor
	*/

	this->hit = false;
	this->material_ptr = NULL;
	this->depth = 0;
	this->t = 0.0;
	this->w = &wr;
}
