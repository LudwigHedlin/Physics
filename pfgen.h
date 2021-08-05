#include "Particle.h"
#include <vector>

class ParticleForceGenerator{
    //interface for force generators attaching to particles
public:
    virtual void updateForce(Particle* particle)=0;
};

class ParticleGravity:public ParticleForceGenerator{
public:
    ParticleGravity(real x,real y,real z);
    ParticleGravity(Vec3& g);

    void updateForce(Particle* particle);

public:
    Vec3 gravity;
    


};

class ParticleDrag:public ParticleForceGenerator{
public:
    ParticleDrag(real dragCoefficient1,real dragCoefficient2);

    void updateForce(Particle* particle);

public:
    real dragCoefficient1;
    real dragCoefficient2;
};

class ParticleSpring:public ParticleForceGenerator{
public:
    ParticleSpring(Particle* other,real springConstant,real restLength);

    void updateForce(Particle* particle);
    
    Particle* other;

    real springConstant;
    real restLength;

};

class ParticleAnchoredSpring:public ParticleForceGenerator{
public:
    //The same as the ParticleSpring except the particle as anchored to a pure position instead of another particle
    ParticleAnchoredSpring(Vec3* anchor,real springConstant, real restLength);

    void updateForce(Particle *particle);

    Vec3* anchor;

    real springConstant;
    real restLength;
};


class ParticleForceRegistry{

protected:
    struct ParticleForceRegistration{
        Particle* particle;
        ParticleForceGenerator* fg;
    };

    std::vector<ParticleForceRegistration> registrations;

public:
    void add(Particle* particle,ParticleForceGenerator* fg);

    void remove(Particle* particle, ParticleForceGenerator* fg);

    void clear(); //clear all registrations

    void updateForces();
};