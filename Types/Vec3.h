/*
 * Vec3.h
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#ifndef VEC3_H_
#define VEC3_H_

#include <iostream>

using namespace std;

class Vec3 {
public:
	Vec3();
	Vec3(float x, float y, float z);
	virtual ~Vec3();
	float _x;
	float _y;
	float _z;

	Vec3 normalize(float highOne);

	Vec3& operator += (const Vec3 &myPoint) { _x += myPoint._x , _y += myPoint._y , _z += myPoint._z; return *this; }
	Vec3& operator -= (const Vec3 &myPoint) { _x -= myPoint._x, _y -= myPoint._y, _z -= myPoint._z; return *this; }
	Vec3& operator + (const Vec3 &myPoint) { _x += myPoint._x, _y += myPoint._y, _z += myPoint._z; return *this; }
	Vec3& operator - (const Vec3 &myPoint) { _x -= myPoint._x, _y -= myPoint._y, _z -= myPoint._z; return *this; }
	Vec3& operator /= (const Vec3 &myPoint) { _x /= myPoint._x , _y /= myPoint._y , _z /= myPoint._z; return *this; }
	Vec3& operator *= (const Vec3 &myPoint) { _x *= myPoint._x, _y *= myPoint._y, _z *= myPoint._z; return *this; }
	Vec3& operator / (const Vec3 &myPoint) { _x /= myPoint._x, _y /= myPoint._y, _z /= myPoint._z; return *this; }
	Vec3& operator * (const Vec3 &myPoint) { _x *= myPoint._x, _y *= myPoint._y, _z *= myPoint._z; return *this; }

	Vec3& operator + (const float &myScale) { _x += myScale, _y += myScale, _z += myScale; return *this; }
	Vec3& operator - (const float &myScale) { _x -= myScale, _y -= myScale, _z -= myScale; return *this; }
	Vec3& operator * (const float &myScale) { _x *= myScale, _y *= myScale, _z *= myScale; return *this; }
	Vec3& operator / (const float &myScale) { _x /= myScale, _y /= myScale, _z /= myScale; return *this; }
	Vec3& operator += (const float &myScale) { _x += myScale, _y += myScale, _z += myScale; return *this; }
	Vec3& operator -= (const float &myScale) { _x -= myScale, _y -= myScale, _z -= myScale; return *this; }
	Vec3& operator *= (const float &myScale) { _x *= myScale, _y *= myScale, _z *= myScale; return *this; }
	Vec3& operator /= (const float &myScale) { _x /= myScale, _y /= myScale, _z /= myScale; return *this; }

	Vec3& operator + (const int &myScale) { _x += myScale, _y += myScale, _z += myScale; return *this; }
	Vec3& operator - (const int &myScale) { _x -= myScale, _y -= myScale, _z -= myScale; return *this; }
	Vec3& operator * (const int &myScale) { _x *= myScale, _y *= myScale, _z *= myScale; return *this; }
	Vec3& operator / (const int &myScale) { _x /= myScale, _y /= myScale, _z /= myScale; return *this; }
	Vec3& operator += (const int &myScale) { _x += myScale, _y += myScale, _z += myScale; return *this; }
	Vec3& operator -= (const int &myScale) { _x -= myScale, _y -= myScale, _z -= myScale; return *this; }
	Vec3& operator *= (const int &myScale) { _x *= myScale, _y *= myScale, _z *= myScale; return *this; }
	Vec3& operator /= (const int &myScale) { _x /= myScale, _y /= myScale, _z /= myScale; return *this; }

	bool operator == (const Vec3 &p2);
	bool operator != (const Vec3 &p2);

	ostream& operator << (ostream& os);



};

#endif /* VEC3_H_ */
