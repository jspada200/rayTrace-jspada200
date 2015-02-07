/*
 * Renderer.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#include "Renderer.h"
#include "Face.h"
#include "Utils.h"

Renderer::Renderer() {
	// TODO Auto-generated constructor stub

}

Renderer::~Renderer() {
	// TODO Auto-generated destructor stub
}

bool Renderer::intersectPlane(const Face &f, Ray ray, float &t)
{
	Vec3 n = f.n;
	Vec3 p0 = f.position;
	Vec3 l0 = ray.getOrigin();
	Vec3 l = ray.getRotation();

    // assuming vectors are all normalized
    double denom = dot(n, l);
    cout << denom << endl;
    if (denom > 1e-6) {
        Vec3 p0l0 = p0 - l0;
        t = dot(p0l0, n) / denom;
        return (t >= 0);
    }
    return false;
}
