/*
 * Scene.h
 *
 *  Created on: Jan 28, 2015
 *      Author: jspada20
 *
 *      Defines a scene object which contains objects and render settings
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "Vec3.h"
#include "Ray.h"
#include "GeometricSolid.h"
#include <vector>
#include <string>

class Scene {

private:

	Vec3 camPos;
	float resStep;

public:
	Scene();
	virtual ~Scene();
	vector<GeometricSolid*> sceneObjects;
	void addSphereGeoObj();
	void addFaceGeoObj();
	float resX;
	float resY;
	string fileName;
};

#endif /* SCENE_H_ */
