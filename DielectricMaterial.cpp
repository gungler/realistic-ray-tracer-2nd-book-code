#include"DielectricMaterial.h"
#include<math.h>

DielectricMaterial::DielectricMaterial(float _nt, const rgb&  _ex)
        :nt(_nt), extinction(_ex){
    R0 = (nt - 1.0f)/(nt+1.0f);
    R0 *= R0;

    float r = log(extinction.r());
    float g = log(extinction.g());
    float b = log(extinction.b());

    extinction = rgb(r, g, b);
}

bool DielectricMaterial::specularDirection(const ONB& uvw,
        const Vector3& in_dir,  //incident vector
        const Vector3& texp,    //Texture point
        const Vector2& uv,      //Texture coordinate
        Vector2& rseed,         //random seed
        rgb& ratio,
        Vector3& reflection){
    
    float scale;
    Vector3 normal = uvw.w();
    float cosine = dot(in_dir, normal);
    if(cosine < 0.0f){
        reflection = reflect(in_dir, uvw.w());
        cosine = -cosine;

        //since assuming dielectrics are imbedded in air no need to
        //check for total interbal reflection here
        float temp1 = 1.0f - cosine;
        scale = R0 + (1.0f - R0)*temp1*temp1*temp1*temp1*temp1;
    }else{  //(cosine >0.0f) ray is outgoing
        reflection = reflection(in_dir, -uvw.w());
        float temp2 = -(dot(in_dir, -normal));
        float root = 1.0f - (nt * nt) * (1.0f - temp2 * temp2);

        if(root < 0.0f) 
            scale = 1.0f;
        else{
            float temp3 = 1.0f - cosine;
            scale = R0 + (1.0f - R0) * temp3*temp3*temp3* temp3*temp3; 
        }
    }
    //we pass back the amount of reflected light
    ratio  = rgb(scale, scale, scale);
    return true;
}
bool DielectricMaterial::transmissionDirection(const ONB& uvw,
        const Vector3& in_dir,
        const Vector3& texp,
        const Vector2& uv,
        const Vector2& rseed,
        rgb& _extinction,
        float& frensnel_scale,
        Vector3& transmission){
    
    Vector3 normal = uvw.w();
    float cosine = dot(in_dir, normal);

    if(cosine< 0.0f){   //ray is incoming
        float temp1 = 1.0f / nt;
        cosine = -cosine;
        float root = 1.0f - (temp1 * temp1) * (1.0f - cosine*cosine);

        //since assuming dielectrics are imbedded in air no need to
        //check for total internal refelction here
        trasmission = in_dir*temp1+normal*(temp1*cosine-sqrt(root));

        _rxtinction = rgb(1.0f, 1.0f, 1.0f);
    }else{  //ray is outgoing
        float temp2 = (dot(in_dir, normal));
        float root = 1.0f - (nt * nt) * (1.0f - temp2 * temp2);

        if(root < 0.0f) return false;
        else transmission = in_dir * nt + -normal*(nt *temp2-sqrt(root));

        _extinction = extinction;
    }
    float temp3 = 1.0f - cosine;
    frensnel_scale = 1.0-(R0+(1.0f - R0)*temp3*temp3*temp3*temp3*temp3);
    return true;
}