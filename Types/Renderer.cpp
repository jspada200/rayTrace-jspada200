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


//Test to see if ray interface intersects plain
//Based on code from scratch a pixel
bool Renderer::intersectPlane(const Face &f, Ray ray, float &t)
{

	//Get variables...
	Vec3 n = f.n;
	n = n.normalize(360);
	Vec3 p0 = f.position;
	Vec3 l0 = ray.getOrigin();
	Vec3 l = ray.getRotation().normalize(360);


	//Debug
	cout << "n: " << n._x << " " << n._y << " " << n._z << endl;
	cout << "p0: " << p0._x << " " << p0._y << " " << p0._z << endl;
	cout << "l0: " << l0._x << " " << l0._y << " " << l0._z << endl;
	cout << "l: " << l._x << " " << l._y << " " << l._z << endl;


    // assuming vectors are all normalized
    double denom = dot(n, l);
    //cout << denom << endl;
    cout << "denom: " << denom << endl;
    if (denom > 1e-6) {
        Vec3 p0l0 = p0 - l0;
        t = dot(p0l0, n) / denom;
        cout << "t: " << t << endl;
        return (t >= 0);
    }
    return false;
}


//Main render fuction
void Renderer::render(vector<Face> &mySceneObjects, int w, int h)
{

	//Storage for pixel values
	vector<float> pixTemp;


	//For each pixel
	for(int j = 0; j < w; j++)
	{
		for(int k = 0; k < h; k++)
		{


			//Create a new ray at the pixel location
			Ray myRay(j,k,0,0,90,0,1);

			//Render the face
			for (unsigned int i = 0; i < mySceneObjects.size(); i++)
			{
				Face newFace = mySceneObjects[i];

				//Stop if we have a hit
				float halt;
				bool hit = false;

				if(intersectPlane(newFace,myRay, halt) == true)
				{
					//cout << "Hit! t = " << halt;
					hit = true;
				}


				//set pixel value
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
			cout << "-----------------------------" << endl;
			}
		}
	}


	//Create and write our image
	Image myImg(w, h);
	for(int i = 0; i<(w*h); i++)
	{
		if(pixTemp[i] == 1)
			myImg.pixels[i] = Image::Rgb(1,1,1);
		else
			myImg.pixels[i] = Image::Rgb(0,0,0);
	}
	string fileName = "/home/jspada20/test.ppm";
	writeFile(myImg,fileName.c_str());

}

//Simple image function from scratch a pixel
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
		 for (unsigned int i = 0; i < img.w * img.h; ++i)
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



//Get the dot product of two points
double Renderer::dot(const Vec3 &p1, const Vec3 &p2)
{
	return ((p1._x*p2._x) + (p1._y*p2._y) + (p1._z*p2._z));
}
