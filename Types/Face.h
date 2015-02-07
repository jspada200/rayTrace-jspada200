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
	vector<Vec3> verts;
	Vec3 n; //Normal

public:
	Face();
	virtual ~Face();
};

#endif /* FACE_H_ */
