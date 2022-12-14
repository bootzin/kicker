#pragma once
#ifndef PARTICLE_CONTACT_INCLUDED_H
#define PARTICLE_CONTACT_INCLUDED_H

#include "Particle.h"

namespace Kicker
{
	class ParticleContactResolver;

	class ParticleContact
	{
		friend class ParticleContactResolver;

	public:
		void SetParticles(Particle* const* particles) { m_Particles[0] = particles[0]; m_Particles[1] = particles[1]; }
		void SetContactNormal(const glm::vec3& normal) { m_ContactNormal = normal; }
		void SetPenetrationDepth(const real penetrationDepth) { m_PenetrationDepth = penetrationDepth; }
		void SetRestitutionCoefficient(const real restitutionCoeff) { m_RestitutionCoeff = restitutionCoeff; }

	protected:
		void Resolve(const real deltaTime);
		real CalculateSeparatingVelocity() const;

	private:
		void ResolveVelocity(const real deltaTime);
		void ResolveInterpenetration(const real deltaTime);

		Particle* m_Particles[2];
		real m_RestitutionCoeff;
		glm::vec3 m_ContactNormal;
		real m_PenetrationDepth;
		glm::vec3 m_ParticleMovement[2];
	};

	class ParticleContactResolver
	{
	public:
		ParticleContactResolver(unsigned int iterations) : m_Iterations(iterations), m_IterationsUsed(0) {}

		void ResolveContacts(ParticleContact* contacts, unsigned int numContacts, real deltaTime);

		void SetIterations(const unsigned int iterations) { m_Iterations = iterations; }
	protected:
		unsigned int m_Iterations;
		unsigned int m_IterationsUsed;
	};
}

#endif // !PARTICLE_CONTACT_INCLUDED_H

