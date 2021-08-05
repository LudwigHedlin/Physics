#include "Particle.h"
void Particle::setMass(const real m) 
{
    if(m>0) inverseMass=((real)1.0)/m;
}

void Particle::setInverseMass(const real m) 
{
    if(m>=0) inverseMass=m;
}

real Particle::getMass() 
{
    return ((real)1.0)/inverseMass;
}

real Particle::getInverseMass() 
{
    return inverseMass;
}

void Particle::update(real dt) 
{
    if(inverseMass<=0) return; //infinite or invalid mass

    acceleration=force*inverseMass;
    position+=velocity*dt;
    velocity+=acceleration*dt;
    velocity=velocity*damping+acceleration*dt;

    clearForce();
}

void Particle::addForce(const Vec3& f) 
{
    force+=f;
}

void Particle::clearForce() 
{
    force.x=0;
    force.y=0;
    force.z=0;
}
