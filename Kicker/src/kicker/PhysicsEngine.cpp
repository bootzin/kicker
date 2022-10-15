#include "kckpch.h"
#include "PhysicsEngine.h"

namespace Kicker
{
	void PhysicsEngine::AddObject(Particle* obj)
	{
		m_Particles.push_back(obj);
	}

	void PhysicsEngine::RemoveObject(Particle* obj)
	{
		m_Particles.erase(std::find(m_Particles.begin(), m_Particles.end(), obj));
	}

	void PhysicsEngine::Simulate(real delta)
	{
		for (unsigned int i = 0; i < m_Particles.size(); i++)
		{
			m_Particles[i]->Integrate(delta);
		}
	}
}