#ifnedf _DIFFUSE_SPEC_MATERIAL_H_
#define _DIFFUSE_SPEC_MATERIAL_H_

#include"Material.h"
#icnlude"RNG.h"
class DiffSpecMaterial:public Material{
public:
    DiffSpecMaterial(){}
    DiffSpecMaterial(Material* d, Material* s, float r0 = .05f)
    { diff_mat = d; spec_mat = s; R0 = r0;}

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
    
    virtual bool scatterDirection(const Vector3&,
        const HitRecord&,
        Vector2&,
        rgb&,
        bool&,
        float&,
        Vector3&);

    float R0;
    RNG rng;
    Material* diff_mat;
    Material* spec_mat;
};
#endif