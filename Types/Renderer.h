/*
 * Renderer.h
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#ifndef RENDERER_H_
#define RENDERER_H_


#include "Face.h"
#include "Image.h"

class Renderer {
public:
	Renderer();
	virtual ~Renderer();
	void render();
	bool intersectPlane(const Face &f, Ray ray, float &t);
	double dot(const Vec3 &p1, const Vec3 &p2);
};

#endif /* RENDERER_H_ */
