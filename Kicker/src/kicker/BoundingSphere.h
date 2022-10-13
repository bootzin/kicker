#pragma once
#ifndef BOUNDING_SPHERE_INCLUDED_H
#define BOUNDING_SPHERE_INCLUDED_H

#include "glm/glm.hpp"
#include "IntersectData.h"
#include "Collider.h"

namespace Kicker {

	class BoundingSphere : public Collider
	{
	public:
		BoundingSphere(const glm::vec3 center, real radius, PhysicsMaterial* material, bool isTrigger = false) : Collider(Collider::TYPE_SPHERE, isTrigger, material), m_center(center), m_radius(radius) {}

		IntersectData IntersectBoundingSphere(const BoundingSphere& other);

		inline const glm::vec3 GetCenter() const { return m_center; }
		inline real GetRadius() const { return m_radius; }
	private:
		glm::vec3 m_center;
		real m_radius;
	};

}

#endif // !BOUNDING_SPHERE_INCLUDED_H



