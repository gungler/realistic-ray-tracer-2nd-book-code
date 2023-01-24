#ifndef _TRIANGLE_H
#define _TRIANGLE_H_
#include"Shape.h"
#include"Vector3.h"
#include"RGB.h"
#include"Ray.h"

class Triangle:public Shape{
public:
    Triangle(const Vector3& _p0, const Vector3& _p1,
            const Vector3& _p2, const rgb& _color);
    bool hit(const Ray& r, float tmin, float tmax, float time,
            HitRecord& record) const;
    
    bool randomPoint(const Vector3& viewpoint, const Vector2& seed,
                float time, Vetcor3& light_point, Vector3& N, float& pdf,
                rgb& radiance)const;
    Vector3 p0;
    Vector3 p1;
    Vector3 p2;

    rgb color;
};
#endif