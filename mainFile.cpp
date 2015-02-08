/*
 * mainFile.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: jspada20
 */

#include <iostream>
#include <cmath>
#include <string>
#include "Types/Vec3.h"
#include "Types/GeometricSolid.h"
#include "Types/Face.h"
#include "Types/Ray.h"
#include "Types/Renderer.h"
#include <fstream>
#include <cstring>


//Todo

//Face Class - Child of Geo Object
// - CheckHit function
//Image Class
// - Read Function
// - Write function
//Camera Class



using namespace std;


int main()
{

	vector<Vec3> verts;
	Vec3 in(25,25,15);
	verts.push_back(in);
	//in = (25,-25,15);
	in._x = 25;
	in._y = -25;
	in._z = 15;
	verts.push_back(in);
	//in = (-25,-25,15);
	in._x = -25;
	in._y = -25;
	in._z = 15;
	verts.push_back(in);
	//in = (-25,25,15);
	in._x = -25;
	in._y = 25;
	in._z = 15;
	verts.push_back(in);
	Vec3 n(90,89,90);

	Face newFace(verts, n);

	vector<Face> mySceneObjects;

	Face newObj(verts, n);

	mySceneObjects.push_back(newObj);

	Renderer myRenderer;
	int w = 500;
	int h = 500;
	myRenderer.render(mySceneObjects, w, h);

	return 0;
}
