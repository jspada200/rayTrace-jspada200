/*
 * Renderer.h
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#ifndef RENDERER_H_
#define RENDERER_H_


#include "Face.h"

class Renderer {
public:
	Renderer();
	virtual ~Renderer();
	void render();
	bool intersectPlane(const Face &f, Ray ray, float &t);
};

#endif /* RENDERER_H_ */
