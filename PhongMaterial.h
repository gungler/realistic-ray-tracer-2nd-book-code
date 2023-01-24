#ifnedf _PHONG_MATERIAL_H_
#define _PHONG_MATERIAL_H_
#include "Material.h"
class Texture;
class PhongMetalMaterial:public Material{
public:
    PhongMetalMaterial(Texture *rt, Texture *et)
    { R = rt; phong_exp = et; }

    virtual rgb ambientResponse(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&);
    
    virtual bool specularDirection(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&);
    
    Texture* R;
    Texture* phong_exp;
};
#endif