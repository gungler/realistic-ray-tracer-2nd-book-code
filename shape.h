#ifndef _SHAPE_H_
#define _SHAPE_H_
#include"Ray.h"
#include"Vector3.h"
#include"RGB.h"
#include"Texture.h"

class ray;
class rgb;

struct HitRecord{
    float t;
    Vector3 normal;
    Vector2 uv;
    Vector3 hit_p;
    Texture* hit_tex;
    rgb color;
};

class Shape{
public:
    virtual bool hit(const Ray& r, float tmin, float tmax, float time,
                        HitRecord& record) const  = 0;
    virtual bool shadowHit(const Ray& r, float tmin, float tmax,
                            float time)const = 0;
};


#endif