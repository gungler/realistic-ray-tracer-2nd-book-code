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

    bool randomPoint(const Vector3& viewpoint, cosnt Vector2& seed,
                    float time, Vector3& on_light, Vector3& N, float& pdf, rgb& E) const;
    Vector3 center;
    float radius;
    rgb color;
};

#endif