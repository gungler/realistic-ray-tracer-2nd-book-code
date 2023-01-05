#ifndef _MARBLE_TEXTURE_H_
#define _MARBLE_TEXTURE_H_

#include<math.h>
#include"Texture.h"
#include"rgb.h"
#include"SolidNoise.h"

class MarbleTexture:public Texture{
public:
    MarbleTexture(float stripes_per_unit, float _scale = 5.0f,
                    int _octaves = 8){
        freq = M_PI * stripes_per_unit;
        scale = _scale;
        octaves = _octaves;

        c0 = rgb(0.8, 0.8, 0.8);
        c1 = rgb(0.4, 0.2, 0.1);
        c2 = rgb(0.06, 0.04, 0.02);
    }
}

#endif