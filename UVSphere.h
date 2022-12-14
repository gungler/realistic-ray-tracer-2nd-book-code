#ifndef _UV_SPHERE_H_
#define _UV_SPHERE_H_
#include"Shape.h"
#include"Vector3.h"
#include"Ray.h"
#include"Texture.h"

class UVSphere:public Shape{
public:
    UVSphere(const Vector3& _center, float _radius, Texture* tex);
    BBox boundingBox() const;
    bool hit(const Ray& r, float tmin, flaot tmax, float time,
                HitRecord& record) const;
    bool shadowHit(const Ray& r, float tmin, float tmax, float time)const;

    Vector3 center;
    float radius;
    Texture* tex;
};

#endif