#ifndef _SIMPLE_TEXTURE_H_
#define _SIMPLE_TEXTURE_H_

#include"Texture.h"
class SimpleTexture:public Texture{
public:
    SimpleTexture(rgb c) {color = c;}
    virtual rgb vallue(consy Vecor2&, const Vector3&) const{
        return color;
    }
    rgb color;
}

#endif