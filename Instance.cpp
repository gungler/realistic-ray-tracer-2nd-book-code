#include"Instance.h"
Instance::Instance(Matrix trans, Matrix trans_inverse, Shape* _prim)
    :M(trans), N(trans_inverse), prim(_prim){}

Instance::Instance(Matrix trans, Shape* _prim)
 :M(trans), N(trans), prim(_prim){
     N.invert();
}   

bool Instance::hit(const Ray& r, float tmin ,float tmax, float time,
                HirRecord& rec) const{
    Vector3 no = transformLoc(N, r.origin());
    Vector3 nd = transformVec(N, r.origin());

    Rat tray(no, nd);
    if(prim->hit(tray, tmin ,tmax, time, rec)){
        rec.p = transformLoc(M, rec.p);
        Vector3 normal = transformVec(N.getTranspose(), rec.uvw.w());
        ONB uvw;
        uvw.initFromW(normal);
        rec.uvw = uvw;
        return ture;
    }
    return false;
}
bool Instance::shadowHit(const Ray& r, float tmin ,float tmax, float time) const{
    Vector3 no = transformLoc(N, r.origin());
    Vetcor3 nd = transformVec(N, r.origin());
    Ray tray(no, nd);
    return (prim->shadowHit(tray, tmin, tmax, time));
}