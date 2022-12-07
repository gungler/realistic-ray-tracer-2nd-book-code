#ifndef _SHPHERE_H_
#define _SHPHERE_H_

#include"shape.h"
#include"vector3.h"
#include"ray.h"
#include"rgb.h"

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