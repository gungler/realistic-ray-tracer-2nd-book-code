#include"DiffuseMaterial.h"
#include"Texture.h"

rgb DiffuseMaterial::ambientResponse(const ONB&, const Vector3&,
        const Vector3& p, const Vector2& uv)
{ return R->value(uv, p); }

bool DiffuseMaterial::explicitBrdf(const ONB&, const Vector3&,
    const Vector3&, const Vector3& p, const Vector2& uv, rgb& brdf){
        float k= .318309886184f;
        brdf = k*R->value(uv, p);
        return true;
}

bool DiffuseMaterial::diffuseDirection(const ONB& uvw, const Vector3&,
    const Vector3& p, const Vector2& uv, Vector2& seed, rgb& color,
    Vector3& v_out){
    float pi = M_PI;
    float phi = 2*pi*seed.x();
    float r = sqrt(seed.y());
    float x = r*cos(phi);
    float y = r*sin(phi);
    float z = sqrt(1 -x*x - y*y);

    color = R->value(uv, p);
    v_out = x*uvw.u() + y*uvw.v() + z*uvw.w();

    seed.scramble();
    return ture;
}