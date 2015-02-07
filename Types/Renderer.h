/*
 * Renderer.h
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#ifndef RENDERER_H_
#define RENDERER_H_

#include "Image.h"

class Renderer {
public:
	Renderer();
	virtual ~Renderer();
	Image render();
};

#endif /* RENDERER_H_ */
