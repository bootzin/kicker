#pragma once
#ifndef PARTICLE_INCLUDED_H
#define PARTICLE_INCLUDED_H

#include <glm/glm.hpp>
#include "Log.h"

namespace Kicker
{
	class Particle
	{
	public:
		const glm::vec3 GetPosition() const { return m_Position; }
		const glm::vec3 GetVelocity() const { return m_Velocity; }
		const glm::vec3 GetAcceleration() const { return m_Acceleration; }
		const glm::vec3 GetForceAccumulated() const { return m_ForceAccum; }
		const real GetDamping() const { return m_Damping; }
		const real GetInverseMass() const { return m_InverseMass; }
		const real GetMass() const
		{
			if (m_InverseMass == 0)
				return REAL_MAX;
			return ((real)1.) / m_InverseMass;
		}
		const bool HasFiniteMass() const { return m_InverseMass >= 0; }

		void SetPosition(const glm::vec3& position) { m_Position = position; }
		void SetVelocity(const glm::vec3& velocity) { m_Velocity = velocity; }
		void SetAcceleration(const glm::vec3& acceleration) { m_Acceleration = acceleration; }
		void SetDamping(const real damping) { m_Damping = damping; }
		void SetInverseMass(const real inverseMass) { m_InverseMass = inverseMass; }
		void SetMass(const real mass) { KCK_ASSERT(mass != 0, "Mass cannot be 0."); m_InverseMass = ((real)1.) / mass; }

		void AddForce(const glm::vec3& force) { m_ForceAccum += force; }
		const void ClearAccumForce() { m_ForceAccum = { 0, 0, 0 }; }

		void Integrate(const real deltaTime);
	private:
		glm::vec3 m_Position;
		glm::vec3 m_Velocity;
		glm::vec3 m_Acceleration;
		glm::vec3 m_ForceAccum;
		real m_Damping;
		real m_InverseMass;
	};
}

#endif // !PARTICLE_INCLUDED_H

