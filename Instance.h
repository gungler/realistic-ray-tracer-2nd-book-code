#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include"Shape.h"
#include"Matrix.h"

class Matrix;

class Instance:public Shape{
public:
    Instance(){}
    ~Instance(){}
    Instance(Matrix trans, Matrix trans_inverse, Shape* _prim);
    Instance(Matrix trans, Shape* _prim);

    bool hit(const Ray& r, float tmin ,float tmax, float time,
                HirRecord& rec) const;
    bool shadowHit(const Ray& r, float tmin ,float tmax, float time) const;
    Matrix M;
    Matrix N;
    Shape* prim;
};

#endif