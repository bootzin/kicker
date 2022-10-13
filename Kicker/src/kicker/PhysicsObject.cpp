#include "kckpch.h"
#include "PhysicsObject.h"

namespace Kicker
{
	void PhysicsObject::Integrate(const float delta)
	{
		m_position += m_velocity * delta;
	}
}