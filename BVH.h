#ifndef _BVH_H_
#define _BVH_H_

#include"Shape.h"
#include"BBox.h"

class BVH:public Shape{
public:
    BVH();
    BVH(Shape** surfaces, int num_surfaces);
    BVH(Shape* prim1, Shape* prim2);
    BVH(Shape* prim1, Shape* prim2, const BBox& _bbox);
    bool hit(const Ray& r, float tmin ,float tmax, float time,
                HitRecord& rec)  const;
    bool shadowHit(const Ray& r,float tmin, float tmax, float time) const;
    BBox boundingBox(float time0, float time1) const;
    Shape* buildBranch(Shape** surfaces, int num_surfaces, int axis = 0);

    BBox bbox;
    Shape* left;
    Shape* right;
};

inline BVH::BVH(Shape* prim1, Shape* prim2, const BBox& _bbox){
    bbox = _bbox;
    left = prim1;
    right = prim2;
}

inline BVH::BVH(Shape* prim1, Shape* prim2){
    left = prim1;
    right = prim2;
    bbox = surround(prim1->boundingBox(0.0f, 0.0f),
                    prim2->boundingBox(0.0f, 0.0f));
}

#endif