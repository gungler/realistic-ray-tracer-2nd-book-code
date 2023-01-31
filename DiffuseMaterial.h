#ifndef _DIFFUSE_MATERIAL_H_
#define _DIFFUSE_MATERIAL_H_

#include"Material.h"

class Texture;
class DiffuseMaterial:public Material{
public:
    DiffuseMaterial(Texture* t)
    { R = t;}

    virtual rgb ambientResponse(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&);
    virtual bool explicitBrdf(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector3&,
        const Vector2&,
        rgb&);
    virtual bool diffuseDirection(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&,
        Vector2&,
        rgb&,
        Vector3&);
    Texture* R;
};
#endif
