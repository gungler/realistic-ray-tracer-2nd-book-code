#include"DynSphere.h"

DynSphere::DynSphere(const Vector3& _ocenter, float _radius,
                    const rgb& _color, float min_time, float max_time)
                    :ocenter(_ocenter), radius(_radius), color(_color), mintime(min_time),
                    maxtime(max_time){}

bool DynSphere::hit(const Ray& r, float tmin, float tmax, float time,
                    HitRecord& record) const{
    Vector3 new_center = getCenter(time);
    Vector3 temp = r.origin() - new_center;

    double a = dot(r.direction(), r.direction());
    double b = 2*dot(r.direction(), temp);
    double c = dot(temp, temp) - radius * radius;

    double discriminant = b*b - 4 * a * c;

    //first check to see if ray intersects sphere
    if(discriminant > 0){
        discriminant = sqrt(discriminant);
        double t = (- b - discriminant) / (2 * a);

        //now check for valid interval
        if(t < tmin)
            t = (-b + discriminant)/(2*a);
        if(t < tmin || t > tmax)
            return false;
        
        //we have a valid hit
        record.t = t;
        record.normal = unitVector(r.origin() + t*r.direction() - new_center);
        record.color = color;
        return true;
    }
    return false;
}

bool DynSphere::shadowHit(const Ray& r, float tmin ,float tmax, 
                        float time) const{
    Vector3 new_center = getCenter(time);
    Vector3 temp = r.origin() - new_center;

    double a = dot(r.direction(), r.direction());
    double b = 2*dot(r.direction(), temp);
    double c = dot(temp, temp) - radius*radius;

    double discriminant = b*b - 4*a*c;

    //first check to see if ray intersects sphere
    if(discriminant > 0){
        discriminant = sqrt(discriminant);
        double t = (-b - discriminant)/(2*a);

         //now check for valid interval
        if(t < tmin)
            t = (-b + discriminant)/(2*a);
        if(t < tmin || t > tmax)
            return false;

        //we have a valid hit
        return true;
    }
    return false;
}

Vector3 DynSphere::getCenter(float time) const{
    float realtime = time*maxtime + (1.0f - time)*mintime;
    return Vector3(ocenter.x()+realtime,
                    ocenter.y()+realtime,
                    ocenter.z()+realtime);
}