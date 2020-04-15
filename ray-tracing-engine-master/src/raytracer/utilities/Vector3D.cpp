#include <sstream>
#include <string>
#include <cmath>

#include "Vector3D.hpp"
#include "Point3D.hpp"

Vector3D::Vector3D()
{
    /*
        Constructor: Sets vector to (0, 0, 0)
    */

    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3D::Vector3D(double c)
{
    /*
        Constructor: Sets vector to (c, c, c)

        @param [double] c: The component of vector along a each axis
    */

    this->x = c;
    this->y = c;
    this->z = c;
}

Vector3D::Vector3D(double _x, double _y, double _z)
{
    /*
        Constructor: Sets vector to (x,y,z)

        @param [double] _x: The component of point along a x axis
        @param [double] _y: The component of point along a y axis
        @param [double] _z: The component of point along a z axis
    */

    this->x = _x;
    this->y = _y;
    this->z = _z;
}

Vector3D::Vector3D(const Point3D &p)
{
    /*
        Constructor: Construct vector from a point

        @param [Point3D] p: Any point
    */

    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

Vector3D &Vector3D::operator=(const Point3D &rhs)
{
    /*
        Operator overload: Overloads the '=' operator

        @param [Vector3D] rhs: Any other vector
        @return [Vector3D]: This vector with new passed vector
    */

    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return (*this);
}

std::string Vector3D::to_string() const
{
    /*
        Converts the vector into its string representation

        @return [std::string]: Vector's string representation
    */

    std::stringstream ss_x(std::stringstream::in | std::stringstream::out);
    ss_x << x;
    std::string t_x = ss_x.str();

    std::stringstream ss_y(std::stringstream::in | std::stringstream::out);
    ss_y << y;
    std::string t_y = ss_y.str();

    std::stringstream ss_z(std::stringstream::in | std::stringstream::out);
    ss_z << z;
    std::string t_z = ss_z.str();

    return "(" + t_x + ", " + t_y + ", " + t_z + ")";
};

Vector3D Vector3D::operator-(void) const
{
    /*
        Operator overload: Overloads the '-' operator for unary operation

        @return [Vector3D]: New vector
    */

    return Vector3D(-this->x, -this->y, -this->z);
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    /*
        Operator overload: Overloads the '+' operator for addition of vectors

        @param [Vector3D] v: Any other vector
        @return [Vector3D]: New vector after addition
    */
    return (Vector3D(this->x + v.x, this->y + v.y, this->z + v.z));
}

// compound addition.
Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    /*
        Operator overload: Overloads the '+=' operator for compound addition of vectors

        @param [Vector3D] v: Any other vector
        @return [Vector3D]: This vector after addition
    */

    this->x += v.x;
    this->y += v.y;
    this->z += v.z;

    return (*this);

    return (*this);
}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    /*
        Operator overload: Overloads the '-' operator for subtraction of vectors

        @param [Vector3D] v: Any other vector
        @return [Vector3D]: New vector after subtraction
    */
    return (Vector3D(this->x - v.x, this->y - v.y, this->z - v.z));
}

Vector3D Vector3D::operator-=(const Vector3D &v)
{
    /*
        Operator overload: Overloads the '-=' operator for compound subtraction of vectors

        @param [Vector3D] v: Any other vector
        @return [Vector3D]: This vector after subtraction
    */

    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;

    return (*this);
}

Vector3D Vector3D::operator*(const double a) const
{
    /*
        Operator overload: Overloads the '*' operator for scaling the vector by a factor

        @param [double] a: Scaling factor
        @return [Vector3D]: New vector after scaling
    */
    return (Vector3D(this->x * a, this->y * a, this->z * a));
}

Vector3D Vector3D::operator/(const double a) const
{
    /*
        Operator overload: Overloads the '/' operator for shrinking the vector by a factor

        @param [double] a: Shrinking factor
        @return [Vector3D]: New vector after shrinking
    */
    return (Vector3D(this->x / a, this->y / a, this->z / a));
}

void Vector3D::normalize(void)
{
    /*
        Nomalize - convert to a unit vector
    */

    double length = this->length();
    this->x /= length;
    this->y /= length;
    this->z /= length;
}

double Vector3D::length() const
{
    /*
        Calculates the length of the vector

        @return [double]: Length of vector
    */

    return (std::sqrt(x * x + y * y + z * z));
}

double Vector3D::len_squared() const
{
    /*
        Calculates the square of length of the vector

        @return [double]: Square of length of vector
    */

    return (x * x + y * y + z * z);
}

double Vector3D::operator*(const Vector3D &v) const
{
    /*
        Operator overload: Overloads the '*' operator for dot product between vectors

        @param [Vector3D] b: Any other vector
        @return [double]: Dot product
    */

    return (x * v.x + y * v.y + z * v.z);
}

Vector3D Vector3D::operator^(const Vector3D &v) const
{
    /*
        Operator overload: Overloads the '^' operator for cross product between vectors

        @param [Vector3D] v: Any other vector
        @return [Vector3D]: Cross product
    */

    return (Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}

Vector3D operator*(const double a, const Vector3D &v)
{
    /*
        Operator overload: Overloads the '*' operator for scaling any vector by a factor

        @param [double] a: Scaling factor
        @param [Vector3D] pt: Any other vector
        @return [Vector3D]: New vector after scaling
    */

    return (Vector3D(v.x * a, v.y * a, v.z * a));
}
