#ifndef _BBOX_H_
#define _BBOX_H_

#include"Ray.h"

class BBox{
public:
    BBox(){}
    BBox(const Vector3& a, const Vector3& b){ pp[0] = a; pp[1] = b; }
    Vector3 min() const { return pp[0];}
    Vector3 max() const { return pp[1];}
    bool rayIntersec(const Ray& r, float tmin ,float tmax) const;

    Vector3 pp[2];
};

inline BBox surround(const BBox& b1, const BBox& b2){
    return BBox(
        Vector3(b1.min().x()< b2.min().x()? b1.min().x():b2.min().x(),
                b1.min().y()< b2.min().y()? b1.min().y():b2.min().y(),
                b1.min().z()< b2.min().z()? b1.min().z():b2.min().z()),

        Vector3(b1.max().x()< b2.max().x()? b1.max().x():b2.max().x(),
                b1.max().y()< b2.max().y()? b1.max().y():b2.max().y(),
                b1.max().z()< b2.max().z()? b1.max().z():b2.max().z()) );
}

inline bool BBox::rayIntersec(const Ray& r, float tmin, float tmax) const{
    float interval_min = tmin;
    float interval_max = tmax;

    int posneg = r.posneg[0];
    float t0 = (pp[posneg].e[0] - r.data[0].e[0]) * r.data[2].e[0];
    float t1 = (pp[1-posneg].e[0] - r.data[0].e[0])*r.data[2].e[0];
    if(t0 >interval_min) interval_min = t0;
    if(t1< interval_min) interval_max = t1;
    if(interval_min > interval_max) return false;

    posneg = r.posneg[1];
    t0 = (pp[posneg].e[1] - r.data[0].e[1]) * r.data[2].e[1];
    t1 = (pp[1-posneg].e[1] - r.data[0].e[1])*r.data[2].e[1];
    if(t0 >interval_min) interval_min = t0;
    if(t1< interval_min) interval_max = t1;
    if(interval_min > interval_max) return false;

    posneg = r.posneg[2];
    t0 = (pp[posneg].e[2] - r.data[0].e[2]) * r.data[2].e[2];
    t1 = (pp[1 - posneg].e[2] - r.data[0].e[2])*r.data[2].e[2];
    if(t0 >interval_min) interval_min = t0;
    if(t1< interval_min) interval_max = t1;
    return (interval_min <= interval_max);
}

#endif