#ifndef _RAY_H_
#define _RAY_H_
#include"Vector3.h"

class Ray{
public:
    Ray(){}
    Ray(const Vector3& a, const Vector3& b)
    { data[0] = a; setDirection(b); }

    Ray(const Ray& r) {*this = r;}
    Ray& operator=(const Ray& original);
    { setOrigin(original.data[0]; setDirection(original.data[1]));}

    Vector3 origin() const { return data[0]; }
    Vector3 direction() const { return data[1]; }
    Vector3 invDirection() const { return data[2]; }
    void setDirection(const Vector3& v){
        data[1] = v;
        data[2] = Vector3(1.0f/v.x(), 1.0f/ v.y(), 1.0f/v.z());

        posneg[0] = (data[1].x() > 0? 0:1);
        posneg[1] = (data[1].y() > 0? 0:1);
        posneg[2] = (data[1].z() > 0? 0:1);
    }

    Vector3 pointAtParameter(float t) const
    { return data[0] + t * data[1]; }

    Vector3 data[2];
    int posneg[3];
};

inline ostream& operator<<(ostream& os, const Ray& r){
    os << "(" << r.origin() << ") + t(" << r.direction() << ")";
    return os;
}

#endif 