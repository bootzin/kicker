#pragma once
#ifndef BOUNDING_SPHERE_INCLUDED_H
#define BOUNDING_SPHERE_INCLUDED_H

#include "glm/glm.hpp"
#include "IntersectData.h"

namespace Kicker {

	class BoundingSphere
	{
	public:
		BoundingSphere(const glm::vec3 center, float radius) : m_center(center), m_radius(radius) { }

		IntersectData IntersectBoundingSphere(const BoundingSphere& other);

		inline const glm::vec3 GetCenter() const { return m_center; }
		inline float GetRadius() const { return m_radius; }
	private:
		glm::vec3 m_center;
		float m_radius;
	};

}

#endif // !BOUNDING_SPHERE_INCLUDED_H



