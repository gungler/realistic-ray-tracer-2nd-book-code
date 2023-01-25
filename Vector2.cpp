#include"Vector2.h"

istream& operator>>(istream& is, Vector2& t){
    float temp;
    is>>temp;
    t.e[0] = temp;
    is>>temp;
    t.e[1] = temp;

    return is;
}

ostream& operator<<(ostream& os, const Vector2& t){
    os << '(' << t.e[0] <<" "<< t.e[1]<<')';
    return os;
}