/*
 * Face.h
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#ifndef FACE_H_
#define FACE_H_

#include "GeometricSolid.h"
#include <vector>

class Face: public GeometricSolid {

private:


public:
	Face();
	Face(vector<Vec3> nVerts, Vec3 normal) {verts = nVerts; n = normal; position._x = 0; position._y = 0; position._z = 15;}
	virtual ~Face();
	vector<Vec3> verts;
	Vec3 n; //Normal
};

#endif /* FACE_H_ */
