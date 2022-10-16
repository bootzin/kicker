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

		real dragCoeff = glm::length(vel);
		dragCoeff = m_K1 * dragCoeff + m_K2 * dragCoeff * dragCoeff;

		glm::vec3 force = -dragCoeff * glm::normalize(vel);
		particle->AddForce(force);
	}

	// Particle Spring
	void SpringForceGenerator::UpdateForce(Particle* particle, real deltaTime)
	{
		glm::vec3 distance = particle->GetPosition() - m_OtherEnd->GetPosition();
		real distMagnitude = glm::length(distance);

		if (m_IsBungee && distMagnitude < m_RestLength)
			return;
		
		real magnitude = (distMagnitude - m_RestLength);

		glm::vec3 force = -m_SpringConstant * magnitude * glm::normalize(distance);
		particle->AddForce(force);
	}

	// Anchored Spring
	void AnchoredSpringForceGenerator::UpdateForce(Particle* particle, real deltaTime)
	{
		glm::vec3 distance = particle->GetPosition() - *m_OtherEnd;
		real distMagnitude = glm::length(distance);

		if (m_IsBungee && distMagnitude < m_RestLength)
			return;

		real magnitude = (distMagnitude - m_RestLength);

		glm::vec3 force = -m_SpringConstant * magnitude * glm::normalize(distance);
		particle->AddForce(force);
	}

	// Buyoancy
	void BuyoancyForceGenerator::UpdateForce(Particle* particle, real deltaTime)
	{
		real depth = particle->GetPosition().y;

		if (depth >= m_LiquidHeight + m_MaxDepth)
			return;

		glm::vec3 force(0);

		if (depth <= m_LiquidHeight - m_MaxDepth)
		{
			force.y = m_LiquidDensity * m_Volume;
			particle->AddForce(force);
			return;
		}

		force.y = m_LiquidDensity * m_Volume * (depth - m_MaxDepth - m_LiquidHeight) / 2 * m_MaxDepth;
		particle->AddForce(force);
	}
}