#include "kckpch.h"
#include "Aabb.h"

namespace Kicker {
	
	IntersectData AABB::IntersectAABB(const AABB& other) const
	{
		glm::vec3 distances1 = other.GetMinExtents() - m_max;
		glm::vec3 distances2 = m_min - other.GetMaxExtents();
		glm::vec3 distances = glm::max(distances1, distances2);

		real maxDistance = glm::max(distances[0], glm::max(distances[1], distances[2]));

		return IntersectData(maxDistance < 0, maxDistance);
	}

}
