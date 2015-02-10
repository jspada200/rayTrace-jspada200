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

//Camera Class



using namespace std;


int main()
{

	//Create Test Object

	//not importent vert data....
	vector<Vec3> verts;
	Vec3 in(100,100,15);
	verts.push_back(in);
	//in = (25,-25,15);
	in._x = 100;
	in._y = -100;
	in._z = 15;
	verts.push_back(in);
	//in = (-25,-25,15);
	in._x = -100;
	in._y = -100;
	in._z = 15;
	verts.push_back(in);
	//in = (-25,25,15);
	in._x = -100;
	in._y = 100;
	in._z = 100;
	verts.push_back(in);


	Vec3 n(90,0,90);

	Face newObj(verts, n);

	//Object DB
	vector<Face> mySceneObjects;

	mySceneObjects.push_back(newObj);

	//New renderer
	Renderer myRenderer;
	int w = 50; //Width of img
	int h = 50; //Height of img
	myRenderer.render(mySceneObjects, w, h); //pass onbject, width, and height

	return 0;
}
