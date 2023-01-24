#include"Sphere.h"
Sphere::Sphere(const Vector3& _center, float _radius, const rgb& _color)
                :center(_center), radius(_radius), color(_color){}

bool Sphere::hit(const Ray& r, float tmin, float tmax, float time,
                HitRecord& record)const{
    Vector3 temp = r.origin() - center;

    double a = dot(r.direction(), r.direction());
    double b = 2*dot(r.direction(), temp);
    double c = dot(temp, temp) - radius*radius;

    double discriminant = b * b - 4 * a * c;

    //first check to see if ray intersects sphere
    if(discriminant > 0){
        discriminant = sqrt(discriminant);
        double t = (-b - discriminant) / (2*a);

        if(t < tmin) 
            t = (- b + discriminant) / (2*a);
        if(t < tmin || t > tmax)
            return false;

        //we have a valid hit
        record.t = t;
        record.normal = unitVector(r.origin() +
                                    t * r.direction() - center);
        record.color = color;
        return true;
    }
}

bool Sphere::shadowHit(const Ray& r, float tmin, float tmax,
                        float time)const{
    Vector3 temp = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2*dot(r.direction(), temp);
    double c = dot(temp, temp) - radius * radius;

    double discriminant = b* b - 4 * a * c;

    //first check to see if ray intersects sphere
    if(discriminant>0){
        discriminant = sqrt(discriminant) / (2*a);

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

bool Sphere::randomPoint(const Vector3& viewpoint, cosnt Vector2& seed,
        float time, Vector3& on_light, Vector3& N, float& pdf, rgb& E) const{
            
    float d = (viewpoint - center).length();
    if(d < radius) return false;
    float r = radius;
    float pi = M_PI;

    //internal angle of cone surrounding light seen from viewpoint
    float sin_alpha_max = r / d;
    float cos_alpha_max = sqrt(1 - sin_alpha_max*sin_alpha_max);
    float q = 1.0/(2*pi*(1 - cos_alpha_max));

    float cos_alpha = 1+seed.x()*(cos_alpha_max - 1);
    float sin_alpha = sqrt(1 - cos_alpha*cos_alpha);

    float phi = 2*pi*seed.y();
    float cos_phi = cos(phi);
    float sin_phi = sin(phi);

    Vector3 k_i(cos_phi*sin_alpha, sin_phi*sin_alpha, cos_alpha);

    //Construct the local coordinate system UVWwhere viewpoint is at
    //the origin and the Sphere is at (0, 0, d) in UVW.
    ONB UVW;
    UVW.initFromW(center - viewpoint);
    Rat to_light(viewpoint, k_i.x()*UVW.u()+k_i.y()*UVW.v()+k_i.z()*UVW.w());

    SurfaceHitRecord rec;
    if(this->hit(to_light, 0.00001, FLT_MAX, time, rec)){
        on_light = rec.p;
        float cos_theta_prime = -dot(rec.uvw.w(), to_light.direction());
        pdf = q * cos_theta_prime /(on_light - viewpoint).squaredLength();
        N = rec.uvw.w();
        E = mat_ptr->emittedRadiance(rec.uvw, -to_light.direction(), on_light, rec.uv);
        return true;
    }else{
        return false;
    }

}