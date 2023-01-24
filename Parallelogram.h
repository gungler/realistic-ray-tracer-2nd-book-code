#ifndef _PARALLELOGRAM_H_
#define _PARALLELOGRAM_H_

#include"Shape.h"
#include"Material.h"
#include"BBox.h"

#define PARALLEL_EPSILON 0.00000001f

class Parallelogram:public Shape{
    Parallelogram(const Vector3& _base, const vector& _u, const Vector3& _v,
            Material* _mptr);
    
    Parallelogram(const Vector3& _base, const Vector3& _u, const Vector3& _v
            const Vector2& _uv0, const Vector2& _uv1, const Vector2& _uv2,
            Material* _mptr);
    bool hit(const Ray& r, float tmin, float tmax, float time,
            HitRecord& rec) const;
    bool shadowHit(const Ray& r, float tmin, float tmax,float time) const;

    BBox boudingBox(float time0, float time1) const;

    bool randomPoint(const Vector3& viewpoint, const Vector2& seed, float time,
            Vector3& light_point, Vector3& N,
            float& pdf, rgb& radiance) const;

    bool randomPoint(const Vector3& viewpoint, const Vector2& seed, float time,
            Vector3& light_point, Vector3& N,
            float& pdf, rgb& radiance) const;
    Vector3 base;
    Vector3 u;
    Vector3 v;

    Vector3 norm;
    Vector3 unorm;
    Vector3 vnorm;

    Vector3 uv0;
    Vector3 uv1;
    Vector3 uv2;

    float _pdf;
    Material* mptr;
}

#endif