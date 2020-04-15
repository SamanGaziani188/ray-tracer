#include "BBox.hpp"
#include "Ray.hpp"
#include "Constants.hpp"
#include "../geometry/Geometry.hpp"

BBox::BBox(const Point3D &min, const Point3D &max)
{
	/*
        Constructor: Sets the points

        @param [Point3D] min: Any other Point3D
        @param [Point3D] max: Any other Point3D
    */

	this->pmin = min;
	this->pmax = max;
}

std::string BBox::to_string() const
{
	/*
        String representation of BBox

        @return [std::string] String representation of BBox
    */

	return "(" + pmax.to_string() + pmax.to_string() + ")";
}

bool BBox::hit(const Ray &ray, float &t_enter, float &t_exit) const
{
	/*
        Checks if ray intersects with the BBox

        @param [Ray] ray: Any Ray
        @param [float] t_enter: Entering time of ray in BBox
		@param [float] t_exit: Exiting time of ray in BBox

		@return [bool]: True if intersection is found

		c/o: https://github.com/team-raytracer/raytracer
    */

	double ox = ray.o.x;
	double oy = ray.o.y;
	double oz = ray.o.z;

	double dx = ray.d.x;
	double dy = ray.d.y;
	double dz = ray.d.z;

	double tx_min, ty_min, tz_min;
	double tx_max, ty_max, tz_max;

	double a = 1.0 / dx;
	if (a >= 0)
	{
		tx_min = (pmin.x - ox) * a;
		tx_max = (pmax.x - ox) * a;
	}
	else
	{
		tx_min = (pmax.x - ox) * a;
		tx_max = (pmin.x - ox) * a;
	}

	double b = 1.0 / dy;
	if (b >= 0)
	{
		ty_min = (pmin.y - oy) * b;
		ty_max = (pmax.y - oy) * b;
	}
	else
	{
		ty_min = (pmax.y - oy) * b;
		ty_max = (pmin.y - oy) * b;
	}

	double c = 1.0 / dz;
	if (c >= 0)
	{
		tz_min = (pmin.z - oz) * c;
		tz_max = (pmax.z - oz) * c;
	}
	else
	{
		tz_min = (pmax.z - oz) * c;
		tz_max = (pmin.z - oz) * c;
	}

	double t0, t1;

	// Finds the largest entering 't' value
	if (tx_min > ty_min)
	{
		t0 = tx_min;
	}
	else
	{
		t0 = ty_min;
	}

	if (tz_min > t0)
	{
		t0 = tz_min;
	}

	// Finds the smallest exiting 't' value
	if (tx_max < ty_max)
	{
		t1 = tx_max;
	}
	else
	{
		t1 = ty_max;
	}

	if (tz_max < t1)
	{
		t1 = tz_max;
	}

	if (t0 < t1 && t1 > kEpsilon)
	{
		t_enter = t0;
		t_exit = t1;
		return true;
	};

	return false;
}

void BBox::extend(Geometry *g)
{
	/*
		Extends this BBox to include g

		@param [Geometry] g: Any Geometry
	*/

	this->pmin = min(this->pmin, g->getBBox().pmin);
	this->pmax = max(this->pmax, g->getBBox().pmax);
};

void BBox::extend(const BBox &b)
{
	/*
		Extends this BBox to include b

		@param [BBox] b: Any other BBox
	*/

	this->pmin = min(this->pmin, b.pmin);
	this->pmax = max(this->pmax, b.pmax);
}

bool BBox::contains(const Point3D &p)
{
	/*
		Checks if this BBox contains 'p'

		@param [Point3D] p: Any other Point3D

		@return [bool] True if BBox contains 'p' or even when 'p' lies on a boundary
	*/

	if (p.x < pmin.x && p.x > pmax.x)
	{
		return false;
	}
	else
	{
		if (p.y < pmin.y && p.y > pmax.y)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool BBox::overlaps(Geometry *g)
{
	/*
		Checks if this BBox overlaps/intersects with 'g'

		@param [Geometry] g: Any Geometry

		@return [bool] True if intersection is found

		c/o https://github.com/team-raytracer/raytracer
	*/

	bool overlapping_x = (pmax.x >= g->getBBox().pmin.x && g->getBBox().pmax.x >= pmin.x);
	bool overlapping_y = (pmax.y >= g->getBBox().pmin.y && g->getBBox().pmax.y >= pmin.y);
	bool overlapping_z = (pmax.z >= g->getBBox().pmin.z && g->getBBox().pmax.z >= pmin.z);

	return overlapping_x && overlapping_y && overlapping_z;
};

bool BBox::overlaps(const BBox &b)
{
	/*
		Checks if this BBox overlaps/intersects with 'b'

		@param [BBox] b: Any other BBox

		@return [bool] True if intersection is found

		c/o https://github.com/team-raytracer/raytracer
	*/

	bool overlapping_x = (pmax.x >= b.pmin.x && b.pmax.x >= pmin.x);
	bool overlapping_y = (pmax.y >= b.pmin.y && b.pmax.y >= pmin.y);
	bool overlapping_z = (pmax.z >= b.pmin.z && b.pmax.z >= pmin.z);

	return overlapping_x && overlapping_y && overlapping_z;
};
