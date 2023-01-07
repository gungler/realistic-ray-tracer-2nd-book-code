#ifndef _MESH_TRI_H_
#define _MESH_TRI_H_

#include"Shape.h"

class Mesh;
class Texture;
class MeshTriangleUV:public Shape{
public:
    MeshTriangleUV();
    MeshTriangleUV(Mesh* _mesh, int p0, int p1, int p2, int index);
    ~MeshTriangle();
    bool hit(const Ray& r, float tmin, float tmax, float time,
                HitRecord& rec) const;
    bool shadowHit(const Ray& r, float tmin ,float tmax, float time) const;

    //data members
    int p[3];
    Mesh* mesh_ptr;
};

#endif