#ifndef IMAGE_H_
#define IMAGE_H_


//Class adapted from http://Scratchapixel.com

#include<string>

using namespace std;

class Image
{
public:
	 // Rgb structure, i.e. a pixel
	 struct Rgb
	 {
	 	Rgb() : r(0), g(0), b(0) {}
	 	Rgb(float c) : r(c), g(c), b(c) {}
	 	Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
	 	bool operator != (const Rgb &c) const { return c.r != r || c.g != g || c.b != b; }
	 	Rgb& operator *= (const Rgb &rgb) { r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this; }
	 	Rgb& operator += (const Rgb &rgb) { r += rgb.r, g += rgb.g, b += rgb.b; return *this; }
	 	friend float& operator += (float &f, const Rgb rgb)
		{ f += (rgb.r + rgb.g + rgb.b) / 3.f; return f; }
	 	float r, g, b;
	 };
	Rgb kBlack = Rgb(0);
	Rgb kWhite = Rgb(1);
	Rgb kRed = Rgb(1,0,0);
	Rgb kGreen = Rgb(0,1,0);
	Rgb kBlue = Rgb(0,0,1);; // preset colors

	 Image() : w(0), h(0), pixels(NULL)
	 { /* empty Image */ }
	 Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack) : w(_w), h(_h), pixels(NULL)
	 {
		 pixels = new Rgb[w * h];
		 for (unsigned int i = 0; i < w * h; ++i) pixels[i] = c;
	 }
	 void setPix_bool(float val[])
	 {
		 for (unsigned int i = 0; i < (w*h); i++)
		 {
			 if(val[i] == 0)
				 pixels[i] = kBlack;
			 else
				 pixels[i] = kWhite;
		 }
	 }

	 const Rgb& operator [] (const unsigned int &i) const { return pixels[i]; }
	 Rgb& operator [] (const unsigned int &i) { return pixels[i]; }
	 ~Image() { if (pixels != NULL) delete [] pixels; }
	 unsigned int w, h; // Image resolution
	 Rgb *pixels; // 1D array of pixels


	 void write(string fileName)
	 {
		 if (w == 0 || h == 0) { fprintf(stderr, "Can't save an empty image\n"); return; }
		 std::ofstream ofs;
		 try
		 {
			 ofs.open(fileName.c_str(), std::ios::binary); // need to spec. binary mode for Windows users
			 if (ofs.fail()) throw("Can't open output file");
			 ofs << "P6\n" << w << " " << h << "\n255\n";
			 unsigned char r, g, b;
			 // loop over each pixel in the image, clamp and convert to byte format
			 for (int i = 0; i < w * h; ++i) {
				 r = static_cast<unsigned char>(std::min(1.f, pixels[i].r) * 255);
				 g = static_cast<unsigned char>(std::min(1.f, pixels[i].g) * 255);
				 b = static_cast<unsigned char>(std::min(1.f, pixels[i].b) * 255);
				 ofs << r << g << b;
			 }

			 ofs.close();
			 std::cout << "Image written to: " << fileName << endl;


		 }
		 catch (const char *err)
		 {
			 fprintf(stderr, "%s\n", err);
			 std::cout << "Image failed to be written out to: " << fileName << endl;
			 ofs.close();
		 }

	 }

};

#endif
