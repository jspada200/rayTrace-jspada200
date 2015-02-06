/*
 * Scene.cpp
 *
 *  Created on: Jan 28, 2015
 *      Author: jspada20
 */

#include "Scene.h"
#include "GeometricSolid.h"
//#include "Sphere.h"
//#include "Face.h"

Scene::Scene() {
	// TODO Auto-generated constructor stub
	resX = 100;
	resY = 100;
	resStep = .1;
	camPos._x = 0;
	camPos._y = 0;
	camPos._z = 0;

}

Scene::~Scene() {
	// TODO Auto-generated destructor stub
}


void Scene::addSphereGeoObj()
{
	cout << "Enter the location for the sphere." << endl;
	cout << "X Position: ";
	double xPos;
	cin >> xPos;
	cout << endl;
	cout << "Y Position: ";
	double yPos;
	cin >> yPos;
	cout << endl;
	cout << "Z Position: ";
	double zPos;
	cin >> zPos;
	cout << endl;

	Vec3 spPos(xPos,yPos,zPos);

	cout << "Enter the radius for the Sphere: ";
	double rad;
	cin >> rad;

//	GeometricSolid *newObject = new Sphere("sp", spPos, rad);
//	sceneObjects.push_back(newObject);
}

void Scene::addFaceGeoObj()
{
	Vec3 p[4];
	for(unsigned int i = 0; i < 4; i++)
	{
		cout << endl << "Enter data for point " << i+1 << endl;
		cout << "X: ";
		cin >> p[i]._x;
		cout << "Y: ";
		cin >> p[i]._y;
		cout << "z: ";
		cin >> p[i]._z;
	}

//	GeometricSolid *newObject = new Face(p[0], p[1], p[2], p[3]);
//	sceneObjects.push_back(newObject);

}
