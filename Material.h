#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include"Vector2.h"
#include"Ray.h"
#include"RGB.h"
#include"ONB.h"

struct SurfaceHitRecord{
    float t;
    Vector3 p;      //point of intersection
    Vector3 texp;   //point of intersection for texture mapping
    ONB uvw;        //w is the outward normal
    Vector2 uv;
    Material *mat_ptr;
};

class Material{
public:
    virtual bool emits() const { return false; }
    virtual bool rgb emittedRadiance(const ONB&,
            const Vector3&,
            const Vector3&,
            const Vector2&)
    { return rgb(0, 0, 0); }

    virtual rgb ambientResponse(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&)
    { return rgb(0, 0, 0); }

    virtual bool explicitBrdf(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector3&,
        const Vector2&,
        rgb&,
        Vector3&){ return false;}
    
    virtual bool diffuseDirection( const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&
        Vector2&,
        rgb&,
        Vector3&){ return false;}

    virtual bool specularDirection(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&,
        Vector2&,
        rgb&,
        Vector3&){ return false;}

    virtual bool transmissionDirection(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&,
        const Vector2&,
        rgb&,
        float&,
        Vector3&){ return false;}

    virtual bool transmissionDirection(const ONB&,
        const Vector3&,
        const Vector3&,
        const Vector2&,
        const Vector2&,
        rgb&,
        float&,
        Vector3&) { return false;}
    
    virtual bool isDiffuse(){ return false; }
    virtual bool isSpecular(){ return false; }
    virtual bool isTransmissive() { return false; }
    virtual int causticPhotos(){ return 0;}
    virtual int globalPhotons(){ return 0;}
    virtual rgb phontonColor(){ return rgb(0.0f, 0.0f, 0.0f); }
};
#endif