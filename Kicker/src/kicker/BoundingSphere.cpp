
#include "kckpch.h"
#include "BoundingSphere.h"


namespace Kicker {
	
	IntersectData BoundingSphere::IntersectBoundingSphere(const BoundingSphere& other)
	{
		float radiusDistance = m_radius + other.m_radius;
		float centerDistance = glm::length(other.GetCenter() - m_center);
		float distance = centerDistance - radiusDistance;

		return IntersectData(centerDistance < radiusDistance, distance);
	}

}
