#pragma once

#ifndef PLANE_INCLUDED_H
#define PLANE_INCLUDED_H

#include "glm/glm.hpp"
#include "BoundingSphere.h"

namespace Kicker {

	class Plane
	{
	public:
		Plane(const glm::vec3& normal, real distance) : m_normal(normal), m_distance(distance) { }

		Plane Normalized() const;

		IntersectData IntersectSphere(const BoundingSphere& sphere) const;

		inline const glm::vec3 GetNormal() const { return m_normal; }
		inline const real GetDistance() const { return m_distance; }
	private:
		const glm::vec3 m_normal;
		const real m_distance;

	};

}

#endif // !PLANE_INCLUDED_H
