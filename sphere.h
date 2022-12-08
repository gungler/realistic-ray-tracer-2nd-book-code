#ifndef _SHPHERE_H_
#define _SHPHERE_H_

#include"Shape.h"
#include"Vector3.h"
#include"Ray.h"
#include"RGB.h"

class Sphere:public Shape{
public:
    Sphere(const Vector3& _center, float _radius, const rgb& _color);
    BBox boundingBox() const;
    bool hit(const Ray& r, float tmin, float tmax, float time,
            HitRecord& record)const;
    bool shaowHit(const Ray& t, float tmin, float tmax, float time) const;

    Vector3 center;
    float radius;
    rgb color;
};

#endif