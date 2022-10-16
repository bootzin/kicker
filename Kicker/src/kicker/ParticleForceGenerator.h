#pragma once
#ifndef PARTICLE_FORCE_GEN_INCLUDED_H
#define PARTICLE_FORCE_GEN_INCLUDED_H

#include "Particle.h"
#include "Core.h"

namespace Kicker
{
	class ParticleForceGenerator
	{
	public:
		virtual void UpdateForce(Particle* particle, real deltaTime) = 0;
	};

	class ParticleForceRegistry
	{
	protected:
        struct ParticleForceRegistration
        {
        public:
            ParticleForceRegistration(Particle* particle, ParticleForceGenerator* fg) : m_Particle(particle), m_ForceGen(fg) {}

            Particle* GetParticle() const { return  m_Particle; }
            ParticleForceGenerator* GetParticleForceGenerator() const { return  m_ForceGen; }
        private:
            Particle* m_Particle;
            ParticleForceGenerator* m_ForceGen;
        };

        std::vector<ParticleForceRegistration> m_Registry;

    public:
        void Add(Particle* particle, ParticleForceGenerator* fg);
        void Remove(Particle* particle, ParticleForceGenerator* fg);
        void Clear();

        void UpdateForces(real deltaTime);
	};

    class GravityForceGenerator : public ParticleForceGenerator
    {
    public:
        GravityForceGenerator(const glm::vec3& gravity) : m_Gravity(gravity) { }

        virtual void UpdateForce(Particle* particle, real deltaTime);
    private:
        glm::vec3 m_Gravity;
    };

    class DragForceGenerator : public ParticleForceGenerator
    {
    public:
        DragForceGenerator(real k1, real k2) : m_K1(k1), m_K2(k2) {}

        virtual void UpdateForce(Particle* particle, real deltaTime) override;
    private:
        real m_K1;
        real m_K2;
    };
}
#endif // !PARTICLE_FORCE_GEN_INCLUDED_H
