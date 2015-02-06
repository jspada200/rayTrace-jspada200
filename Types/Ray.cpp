/*
 * Ray.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#include "Ray.h"


//Constructors
Ray::Ray() {
	// TODO Auto-generated constructor stub
	_origin._x = 0;
	_origin._y = 0;
	_origin._z = 0;
	_rotation._x = 0;
	_rotation._y = 0;
	_rotation._z = 0;
	_threshhold = 0;
}

Ray::Ray(Vec3 origin, Vec3 rotation, float threshhold)
{
	_origin._x = origin._x;
	_origin._y = origin._y;
	_origin._z = origin._z;
	_rotation._x = rotation._x;
	_rotation._y = rotation._y;
	_rotation._z = rotation._z;
	_threshhold = threshhold;
}

Ray::Ray(float origin_x, float origin_y, float origin_z, float rotation_x, float rotation_y, float rotation_z,float threshhold)
{

	_origin._x = origin_x;
	_origin._y = origin_y;
	_origin._z = origin_z;
	_rotation._x = rotation_x;
	_rotation._y = rotation_y;
	_rotation._z = rotation_z;
	_threshhold = threshhold;
}

//Deconstructors
Ray::~Ray() {
	// TODO Auto-generated destructor stub
}

