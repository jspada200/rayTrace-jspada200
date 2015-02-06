/*
 * Ray.h
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#ifndef RAY_H_
#define RAY_H_

#include "Vec3.h"

class Ray {
private:
	Vec3 _origin;
	Vec3 _rotation;
	float _threshhold;

public:
	Ray();
	Ray(Vec3 origin, Vec3 rotation, float threshhold);
	Ray(float origin_x, float origin_y, float origin_z, float rotation_x, float rotation_y, float rotation_z,float threshhold);
	virtual ~Ray();
	Vec3 getOrigin() { return _origin; };
	Vec3 getrotation() { return _rotation; };
};

#endif /* RAY_H_ */
