#include "kckpch.h"
#include "Particle.h"

namespace Kicker
{
	void Particle::Integrate(const real deltaTime)
	{
		// Update linear position
		m_Position += m_Velocity * deltaTime;

		// Work out the acceleration from the force.
		glm::vec3 acc = m_Acceleration + (m_ForceAccum * m_InverseMass);

		// Update linear velocity from the acceleration
		m_Velocity += acc * deltaTime;

		// Impose drag
		m_Velocity *= glm::pow(m_Damping, deltaTime);

		ClearAccumForce();
	}
}