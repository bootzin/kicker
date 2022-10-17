#pragma once
#ifndef PARTICLE_LINK_INCLUDED_H
#define PARTICLE_LINK_INCLUDED_H

#include "Particle.h"
#include "ParticleContact.h"

namespace Kicker
{
	class ParticleLink
	{
	public:
		virtual unsigned int FillContact(ParticleContact* contact, unsigned int limit) const = 0;
	protected:
		const real GetCurrentLength() const { return glm::length(m_Particles[0]->GetPosition() - m_Particles[1]->GetPosition()); }
		Particle* m_Particles[2];
	private:
	};

	class ParticleCable : public ParticleLink
	{
	public:
		virtual unsigned int FillContact(ParticleContact* contact, unsigned int limit) const override;
	private:
		real m_MaxLength;
		real m_RestitutionCoeff;
	};

	class ParticleRod : public ParticleLink
	{
	public:
		virtual unsigned int FillContact(ParticleContact* contact, unsigned int limit) const override;
	private:
		real m_Length;
	};
}

#endif // !PARTICLE_LINK_INCLUDED_H


