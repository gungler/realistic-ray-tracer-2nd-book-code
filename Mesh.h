#ifndef _MESH_H_
#define _MESH_H_

#include"Vertex.h"
#include"Shape.h"
#include"Texture.h"

class Mesh{
public:
    Mesh(){}
    ~Mesh(){}
    Texture* getTexture() const{ return tex; }

    //data members
    Texture* tex;
    Vector3* verts;
    VertexUV* vertexUVs;
    VertexN* vertNs;
    VertexUVN* vertUVNs;
};

#endif