#ifndef _IMAGE_TEXTURE_H_
#define _IMAGE_TEXTURE_H_
#include"Texture.h"

class Image{
    float width() const { return width; }
    float height() const { return height; } 

    float width;
    float height;
};

class ImageTexture:public Texture{
public:
    ImageTexture(char* file_name);
    virtual rgb value(const Vector2& uv, const Vector3& p) const;

    Image* image;
};
#endif