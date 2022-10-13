#pragma once

#ifndef AABB_INCLUDED_H
#define AABB_INCLUDED_H

#include "glm/glm.hpp"
#include "IntersectData.h"
#include "Collider.h"

namespace Kicker {

	class AABB : public Collider
	{
	public:
		AABB(const glm::vec3 min, const glm::vec3 max, PhysicsMaterial* material, bool isTrigger = false) : Collider(TYPE_AABB, isTrigger, material), m_min(min), m_max(max) { }

		IntersectData IntersectAABB(const AABB& other) const;

		inline const glm::vec3 GetMinExtents() const { return m_min; }
		inline const glm::vec3 GetMaxExtents() const { return m_max; }
	private:
		const glm::vec3 m_min;
		const glm::vec3 m_max;
	};

}

#endif // !AABB_INCLUDED_H



