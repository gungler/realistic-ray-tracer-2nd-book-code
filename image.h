#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <cmath>
#include <string>
#include <fstream>
#include "RGB.h"
using namespace std;
class Image{
public:
    Image();
    Image(int width, int height);
    Image(int width, int height, rgb background);

    bool set(int x, int y, const rgb& color);
    void gammaCorrect(float gamma);
    //output PPM image to 'out'
    void writePPM(ostream& out);
    void readPPM(string file_name);

private:
    rgb** raster;
    int nx; //raster width
    int ny; //raster height
};
#endif