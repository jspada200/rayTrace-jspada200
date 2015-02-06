/*
 * GeometricSolid.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: jspada20
 *      Basic null geometeric object
 *      Only contains translation data
 */

#include "GeometricSolid.h"

GeometricSolid::GeometricSolid() {
	// TODO Auto-generated constructor stub
	position._x = 0;
	position._y = 0;
	position._z = 0;
	objName = "null";

}

GeometricSolid::~GeometricSolid() {
	// TODO Auto-generated destructor stub
}


double GeometricSolid::volume()
{
	return 0.0;
}

double GeometricSolid::surfaceArea()
{
	return 0.0;
}

