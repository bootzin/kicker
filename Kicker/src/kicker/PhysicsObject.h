#pragma once

#include "glm/glm.hpp"

namespace Kicker
{
	class PhysicsObject
	{
	public:
		PhysicsObject(glm::vec3 position, glm::vec3 velocity) : m_position(position), m_velocity(velocity) { }

		void Integrate(float delta);

		inline const glm::vec3 GetPosition() const { return m_position; }
		inline const glm::vec3 GetVelocity() const { return m_velocity; }
	private:
		glm::vec3 m_position;
		glm::vec3 m_velocity;
	};
}

