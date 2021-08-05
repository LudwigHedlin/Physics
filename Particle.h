#include "Vector3D.h"

class Particle{
    
public:
    Particle();

    void setMass(const real m);
    void setInverseMass(const real m);
    real getMass();
    real getInverseMass();

    void update(real dt);

    void addForce(const Vec3& f);

    void clearForce();


public:
    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
    Vec3 force;

protected:
    real damping; //will need to be very near 1 since it is not scaled for framerate
    real inverseMass;
};