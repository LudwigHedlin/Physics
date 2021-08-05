#include "pfgen.h"


void ParticleForceRegistry::updateForces() 
{
    for(auto& registry: registrations){
        registry.fg->updateForce(registry.particle);
    }
}

void ParticleForceRegistry::add(Particle* particle,ParticleForceGenerator* fg) 
{
    ParticleForceRegistration pfr;
    pfr.particle=particle;
    pfr.fg=fg;
    registrations.push_back(pfr);
}

void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator* fg) 
{
    //removes specified pair from list if it occurs, does nothing if not 
    //If a pair occurs multiple times it only removes one instance
    for(int i=0;i<registrations.size();i++){
        if(registrations[i].particle==particle&&registrations[i].fg==fg){
            registrations.erase(registrations.begin()+i);
            break;
        }
    }

}

void ParticleGravity::updateForce(Particle* particle) 
{
    particle->force+=gravity;
}

ParticleDrag::ParticleDrag(real dragCoefficient1,real dragCoefficient2) 
{
    this->dragCoefficient1=dragCoefficient1;
    this->dragCoefficient2=dragCoefficient2;
}

void ParticleDrag::updateForce(Particle* particle) 
{
    particle->force-=particle->velocity*(dragCoefficient1+dragCoefficient2*particle->velocity.magnitude());
}

ParticleSpring::ParticleSpring(Particle* other,real springConstant,real restLength) 
{
    this->other=other;
    this->springConstant=springConstant;
    this->restLength=restLength;

}

void ParticleSpring::updateForce(Particle* particle) 
{
    Vec3 posDifference=other->position-particle->position;

    real separation=posDifference.magnitude();
    posDifference.normalize();

    particle->force+=posDifference*(separation-restLength)*springConstant;
}

ParticleAnchoredSpring::ParticleAnchoredSpring(Vec3* anchor,real springConstant, real restLength) 
{
    this->anchor=anchor;
    this->springConstant=springConstant;
    this->restLength=restLength;
}

void ParticleAnchoredSpring::updateForce(Particle *particle) 
{
    Vec3 posDifference = *anchor - particle->position;

    real separation = posDifference.magnitude();
    posDifference.normalize();

    particle->force += posDifference * (separation-restLength)*springConstant;
}

ParticleGravity::ParticleGravity(real x,real y,real z) 
{
    gravity=Vec3(x,y,z);
}

ParticleGravity::ParticleGravity(Vec3& g) 
{
    gravity=g;
}
