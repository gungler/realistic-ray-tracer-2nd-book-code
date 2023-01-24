#include"BVH.h"
#include"qsplit.h"

BVH:BVH(){}

BVH::BVH(Shape** shapes, int num_shapes){
    if(num_shapes == 1) *this = BVH(shapes[0], shapes[0]);
    if(num_shapes == 2) *this = BVH(shapes[0], shapes[1]);

    //find the midpoint of the bounding box to use as a qsplit pivot
    bbox = shapes[0]->boudningBox(0.0f, 0.0f);
    for(int i=1; i<num_shapes; i++)
        bbox = surround(bbox, shapes[i]->boudingBox(0.0f, 0.0f));
    Vector3 pivot = (bbox.max() + bbox.min())/2.0f;

    int mid_point = qsplit(shapes, num_shapes, pivot.x(), 0);

    //create a new boudingVolume
    left = buildBranch(shapes, mid_point, 1);
    right = buildBranch(&shapes[mid_point], num_shapes-mid_point, 1);
}

BBox  BVH::boundingBox(float time0, float time1) const{
    return bbox;
}

bool BVH::hit(const Ray& r, float tmin ,float tmax,float time,
                HitRecord& rec) const{

}

bool BVH::shadowHit(const Ray& r, float tmin, float tmax, float time) const{
    if(!(bbox.rayIntersec(r, tmin, tmax))) return false;

    if(right->shadowHit(r, tmin, tmax, time)) return true;
    return left->shadowHit(r, tmin, tmax, time);
}

boolBVH::buildBranch(Shape** shapes, int shape_size, int axis){
    if(shape_size == 1) return shapes[0];
    if(shape_size == 2) return new BVH(shapes[0], shapes[1]);

    //find the midpoint of  the bounding box to use as a qsplit pivot
    BBox box = shapes[0]->boundingBox(0.0f, 0.0f);
    for(int i = 1; i < shape_size; i++)
        box= surround(box, shapes[i]->boundingBox(0.0f, 0.0f));

    Vector3 pivot = (box.max() + box.min()) / 2.0f;

    //now split according to correct axis
    int mid_point = qspilt(shapes, mid_point, (axis+1)%3);

    //create a new boudingVolume
    Shape* left = buildBranch(shapes, mid_point, (axis+1)%3);
    Shape* right = buildBranch(&shapes[mid_point], shape_size-mid_point, (axis+1)%3);
    return new BVH(left, right, box);
}