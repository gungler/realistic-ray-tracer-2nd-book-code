#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include"Vector2.h"
#include"Vector3.h"
#include"rgb.h"

class Texture{
public:
    //The Vector2 is a UV coord and the Vector3 is the 3D hit point
    virtual rgb value(const Vector2&, const Vector3&) const = 0;
};
#endif