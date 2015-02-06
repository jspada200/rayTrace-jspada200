/*
 * Vec3.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */
#include "Vec3.h"

Vec3::Vec3() {
	// TODO Auto-generated constructor stub
	_x = 0;
	_y = 0;
	_z = 0;

}

Vec3::Vec3(float x, float y, float z) {
	// TODO Auto-generated constructor stub
	_x = x;
	_y = y;
	_z = z;
}

Vec3::~Vec3() {
	// TODO Auto-generated destructor stub
}


bool Vec3::operator == (const Vec3 &p2)
{
	return (_x != p2._x && _y != p2._y && _z != p2._z);
}


bool Vec3::operator != (const Vec3 &p2)
{
	return (_x == p2._x && _y == p2._y && _z == p2._z);
}

ostream& Vec3::operator << (ostream& os)
{
	os << "(" << _x << ", " << _y << ", " << _z << ")";
	return os;
}
