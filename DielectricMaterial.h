#ifnef _DIELECTRIC_MATERIAL_H_
#define _DIELECTRIC_MATERIAL_H_

#include"Material.h"
#include"RGB.h"
#include"Vector3.h"

class Texture;
class DielectricMaterial:public Material{
public:
    DielectricMaterial(){}
    DielectricMaterial(float nt, const rgb& _ex);

    bool specularDirection(const ONB& uvw,
        const Vector3& in_dir,  //incident vector
        const Vector3& texp,    //Texture point
        const Vector2& uv,      //Texture coordinate
        Vector2& rseed,         //random seed
        rgb& ratio,
        Vector3& reflection);

    bool transmissionDirection(const ONB& uvw,
        const Vector3& in_dir,
        const Vector3& texp,
        const Vector2& uv,
        const Vector2& rseed,
        rgb& _extinction,
        float& frensnel_scale,
        Vector3& transmission);

    float R0;
    float nt;
    rgb extinction;
};

#endif