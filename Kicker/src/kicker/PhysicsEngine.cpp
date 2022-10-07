#include "kckpch.h"
#include "PhysicsEngine.h"

namespace Kicker
{
	void PhysicsEngine::AddObject(PhysicsObject* obj)
	{
		m_objects.push_back(obj);
	}

	void PhysicsEngine::Simulate(float delta)
	{
		for (unsigned int i = 0; i < m_objects.size(); i++)
		{
			(*m_objects[i]).Integrate(delta);
		}
	}
}