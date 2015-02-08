/*
 * Renderer.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: jspada20
 */

#include "Renderer.h"
//#include "Face.h"
//#include "Image.h"
#include <iostream>
#include <fstream>

using namespace std;

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
    //cout << denom << endl;
    if (denom > 1e-6) {
        Vec3 p0l0 = p0 - l0;
        t = dot(p0l0, n) / denom;
        return (t >= 0);
    }
    return false;
}


void Renderer::render(vector<Face> &mySceneObjects, int w, int h)
{

	vector<float> pixTemp;

	for(unsigned int j = 0; j < w; j++)
	{
		for(unsigned int k = 0; k < h; k++)
		{
			Ray myRay(j,k,0,0,90,0,1);
			//Render the face
			for (unsigned int i = 0; i < mySceneObjects.size(); i++)
			{
				Face newFace = mySceneObjects[i];
				float halt;
				bool hit = false;
				for(float i = .1; i < 10000; i = i + .1)
				{
					halt = i;
					if(intersectPlane(newFace,myRay, halt) == true)
					{
						//cout << "Hit! t = " << halt;
						hit = true;
						break;
					}
				}
				if(hit)
				{
					pixTemp.push_back(1);
					cout << "+ ";
				}
				else
				{
					pixTemp.push_back(0);
					cout << "- ";
				}
			cout << "(" << j << "," << k << ")" << endl;
			}
		}
	}


	Image myImg(w, h);
	for(unsigned int i = 0; i<(w*h); i++)
	{
		if(pixTemp[i] == 1)
			myImg.pixels[i] = Image::Rgb(1,1,1);
		else
			myImg.pixels[i] = Image::Rgb(0,0,0);
	}
	string fileName = "/home/jspada20/test.ppm";
	writeFile(myImg,fileName.c_str());

}

void Renderer::writeFile(Image &img, const char *filename)
{
	if (img.w == 0 || img.h == 0) { fprintf(stderr, "Can't save an empty image\n"); return; }
	std::ofstream ofs;
	try
	{
		ofs.open(filename, std::ios::binary); // need to spec. binary mode for Windows users
		 if (ofs.fail()) throw("Can't open output file");
		 ofs << "P6\n" << img.w << " " << img.h << "\n255\n";
		 unsigned char r, g, b;
		 // loop over each pixel in the image, clamp and convert to byte format
		 for (int i = 0; i < img.w * img.h; ++i)
		 {
			 r = static_cast<unsigned char>(std::min(1.f, img.pixels[i].r) * 255);
			 g = static_cast<unsigned char>(std::min(1.f, img.pixels[i].g) * 255);
			 b = static_cast<unsigned char>(std::min(1.f, img.pixels[i].b) * 255);
			 ofs << r << g << b;
		 }



	} catch (const char *err)
	{
		fprintf(stderr, "%s\n", err);
		ofs.close();
	}
}



double Renderer::dot(const Vec3 &p1, const Vec3 &p2)
{
	return (p1._x*p2._x) + (p1._y*p2._y) + (p1._z*p2._z);
}
