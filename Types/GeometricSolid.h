/*
 * GeometricSolid.h
 *
 *  Created on: Jan 28, 2015
 *      Author: jspada20
 *      Serves as the basis for all geometric objects in the scene
 */

#ifndef GEOMETRICSOLID_H_
#define GEOMETRICSOLID_H_

#include <iostream>
#include <string>
#include "Vec3.h"
#include "Ray.h"


using namespace std;

class GeometricSolid
{
	protected:

	public:
		GeometricSolid();
		virtual ~GeometricSolid();

		string objName;
		Vec3 position;

		virtual string name() { return objName; }
		virtual double volume();
		virtual double surfaceArea();

		virtual bool chkHit(Ray ray) { cout << "Geo Check Called" << endl; return false; } // used for the ray intersection tests
//		virtual void talk() { cout << "I'm in Geo!" << endl; } // Use this function for debugging if the object is polymorphic

};

#endif /* GEOMETRICSOLID_H_ */
