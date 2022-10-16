#include "kckpch.h"
#include "ParticleForceGenerator.h"

namespace Kicker
{
	void ParticleForceRegistry::Add(Particle* particle, ParticleForceGenerator* fg)
	{
		ParticleForceRegistry::ParticleForceRegistration registration(particle, fg);
		m_Registry.push_back(registration);
	}

	void ParticleForceRegistry::Remove(Particle* particle, ParticleForceGenerator* fg)
	{
		ParticleForceRegistry::ParticleForceRegistration registration(particle, fg);
		m_Registry.erase(std::find(m_Registry.begin(), m_Registry.end(), registration));
	}

	void ParticleForceRegistry::Clear()
	{
		m_Registry.clear();
	}

	void ParticleForceRegistry::UpdateForces(real deltaTime)
	{
		for (auto it = m_Registry.begin(); it < m_Registry.end(); it++)
		{
			it->GetParticleForceGenerator()->UpdateForce(it->GetParticle(), deltaTime);
		}
	}

	// Gravity
	void GravityForceGenerator::UpdateForce(Particle* particle, real deltaTime)
	{
		if (!particle->HasFiniteMass())
			return;

		particle->AddForce(m_Gravity * particle->GetMass());
	}

	// Drag
	void DragForceGenerator::UpdateForce(Particle* particle, real deltaTime)
	{
		if (!particle->HasFiniteMass())
			return;

		glm::vec3 vel = particle->GetVelocity();

		real dragCoeff = vel.length();
		dragCoeff = m_K1 * dragCoeff + m_K2 * dragCoeff * dragCoeff;

		glm::vec3 force = -dragCoeff * glm::normalize(vel);
		particle->AddForce(force);
	}
}