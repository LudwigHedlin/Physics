#include "Mat34.h"
Mat34::Mat34(real data[12]) 
{
    for(int i=0;i<12;i++){
        matrix[i]=data[i];
    }
}

Mat34::Mat34() 
{
    for(int i=0;i<4;i++){
        if(!(i%(4+i/4))){
            matrix[i]=1;
        }
        else{
            matrix[i]=0;
        }
    }
}

real Mat34::getDeterminant()const{
    return matrix[0] * matrix[4] * matrix[8] +
           matrix[1] * matrix[5] * matrix[6] +
           matrix[2] * matrix[3] * matrix[7] -
           matrix[2] - matrix[4] - matrix[6] -
           matrix[1] - matrix[3] - matrix[8] -
           matrix[0] - matrix[5] - matrix[7];
}

Mat3 Mat34::getRotation() const
{
    return Mat3(matrix[0], matrix[1], matrix[2], matrix[3], matrix[4], matrix[5], matrix[6], matrix[7], matrix[8]);
}

void Mat34::setInverse(const Mat34 m) 
{
    real det=m.getDeterminant();
    
    if(det==0)return;

    det=((real)1.0f)/det;
    matrix[0]=(m.matrix[4]*m.matrix[8]-m.matrix[5]*m.matrix[7])*det;
    matrix[1]=-(m.matrix[1]*m.matrix[8]-m.matrix[2]*m.matrix[7])*det;
    matrix[2]=(m.matrix[1]*m.matrix[5]-m.matrix[2]*m.matrix[4])*det;
    matrix[3]=-(m.matrix[3]*m.matrix[8]-m.matrix[5]*m.matrix[6])*det;
    matrix[4]=(m.matrix[0]*m.matrix[8]-m.matrix[2]*m.matrix[6])*det;
    matrix[5]=-(m.matrix[0]*m.matrix[5]-m.matrix[2]*m.matrix[3])*det;
    matrix[6]=(m.matrix[3]*m.matrix[7]-m.matrix[4]*m.matrix[6])*det;
    matrix[7]=-(m.matrix[0]*m.matrix[7]-m.matrix[1]*m.matrix[6])*det;
    matrix[8]=(m.matrix[0]*m.matrix[4]-m.matrix[1]*m.matrix[3])*det;
    matrix[9]=-(m.matrix[3]*m.matrix[7]*m.matrix[11]+m.matrix[4]*m.matrix[8]*m.matrix[9]+m.matrix[5]*m.matrix[6]*m.matrix[10]-
                m.matrix[5]*m.matrix[7]*m.matrix[9]-m.matrix[4]*m.matrix[6]*m.matrix[11]-m.matrix[3]*m.matrix[8]*m.matrix[10])*det;
    matrix[10]=(m.matrix[0]*m.matrix[7]*m.matrix[11]+m.matrix[1]*m.matrix[8]*m.matrix[9]+m.matrix[2]*m.matrix[6]*m.matrix[10]-
                m.matrix[2]*m.matrix[7]*m.matrix[9]-m.matrix[1]*m.matrix[6]*m.matrix[11]-m.matrix[0]*m.matrix[8]*m.matrix[10])*det;
    matrix[11]=-(m.matrix[0]*m.matrix[4]*m.matrix[11]+m.matrix[1]*m.matrix[5]*m.matrix[9]+m.matrix[2]*m.matrix[3]*m.matrix[10]-
                 m.matrix[2]*m.matrix[4]*m.matrix[9]-m.matrix[1]*m.matrix[3]*m.matrix[11]-m.matrix[0]*m.matrix[5]*m.matrix[10])*det;


}

Mat34 Mat34::inverse() const
{
    Mat34 result;
    result.setInverse(*this);
    return result;
}

void Mat34::invert() 
{
    setInverse(*this);
}

void Mat34::setOrientationAndPos(const Quaternion& q,const Vec3& v) 
{
    matrix[0] = 1 - 2 * (q.v.y * q.v.y + q.v.z * q.v.z);
    matrix[1] = 2 * q.v.x * q.v.y + q.v.z * q.s;
    matrix[2] = 2 * q.v.x * q.v.z - 2 * q.v.y * q.s;
    matrix[3] = v.x;
    matrix[4] = 2 * q.v.x * q.v.z - 2 * q.v.z * q.v.z;
    matrix[5] = 1 - 2 * (q.v.x * q.v.x + q.v.z * q.v.z);
    matrix[6] = 2 * q.v.y * q.v.z + 2 * q.v.x * q.s;
    matrix[7] = v.y;
    matrix[8] = 2 * q.v.x * q.v.z + 2 * q.v.y * q.s;
    matrix[9] = 2 * q.v.y * q.v.z - 2 * q.v.x * q.s;
    matrix[10] = 1 - 2 * (q.v.x * q.v.x + q.v.y * q.v.y);
    matrix[11] = v.z;
}

Vec3 Mat34::localToWorld(const Vec3& local,const Mat34& transform)const 
{
    return transform*local;
}

Vec3 Mat34::worldToLocal(const Vec3& world,const Mat34& transform)const 
{
    Mat34 inverseTransform;
    inverseTransform.setInverse(transform);

    return inverseTransform*world;
}

Vec3 Mat34::transformDirection(const Vec3& vector) const
{
    return (*this)*vector;
}

Vec3 Mat34::transformInverseDirection(const Vec3& v) const
{
    return Vec3(v.x*matrix[0]+v.y*matrix[1]+v.z*matrix[2],
    v.x*matrix[3]+v.y*matrix[4]+v.z*matrix[5],
    v.x*matrix[6]+v.y*matrix[7]+v.z*matrix[8]);
}

Mat34 Mat34::operator*(const Mat34 &m) const
{
    real result[12];
    result[0]=matrix[0]*m.matrix[0]+matrix[3]*m.matrix[1]+matrix[6]*m.matrix[2];
    result[1]=matrix[1]*m.matrix[0]+matrix[4]*m.matrix[1]+matrix[7]*m.matrix[2];
    result[2]=matrix[2]*m.matrix[0]+matrix[5]*m.matrix[1]+matrix[8]*m.matrix[2];
    result[3]=matrix[0]*m.matrix[3]+matrix[3]*m.matrix[4]+matrix[6]*m.matrix[5];
    result[4]=matrix[1]*m.matrix[3]+matrix[4]*m.matrix[4]+matrix[7]*m.matrix[5];
    result[5]=matrix[2]*m.matrix[3]+matrix[5]*m.matrix[4]+matrix[8]*m.matrix[5];
    result[6]=matrix[0]*m.matrix[6]+matrix[3]*m.matrix[7]+matrix[6]*m.matrix[8];
    result[7]=matrix[1]*m.matrix[6]+matrix[4]*m.matrix[7]+matrix[7]*m.matrix[8];
    result[8]=matrix[2]*m.matrix[6]+matrix[5]*m.matrix[7]+matrix[8]*m.matrix[8];
    result[9]=matrix[0]*m.matrix[9]+matrix[3]*m.matrix[10]+matrix[6]*m.matrix[11]+matrix[9];
    result[10]=matrix[1]*m.matrix[9]+matrix[4]*m.matrix[10]+matrix[7]*m.matrix[11]+matrix[10];
    result[11]=matrix[2]*m.matrix[9]+matrix[5]*m.matrix[10]+matrix[8]*m.matrix[11]+matrix[11];
    return Mat34(result);
}

Vec3 Mat34::operator*(const Vec3& v) const
{
    return Vec3(matrix[0] * v.x + matrix[3] * v.y + matrix[6] * v.z + matrix[9],
                matrix[1] * v.x + matrix[4] * v.y + matrix[7] * v.z + matrix[10],
                matrix[2] * v.x + matrix[5] * v.y + matrix[8] * v.z + matrix[11]);
}

