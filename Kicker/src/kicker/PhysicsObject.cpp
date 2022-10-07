#include "kckpch.h"
#include "PhysicsObject.h"

namespace Kicker
{
	void PhysicsObject::Integrate(float delta)
	{
		m_position += m_velocity * delta;
	}
}