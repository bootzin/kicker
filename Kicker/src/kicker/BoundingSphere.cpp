
#include "kckpch.h"
#include "BoundingSphere.h"


namespace Kicker {
	
	IntersectData BoundingSphere::IntersectBoundingSphere(const BoundingSphere& other)
	{
		real radiusDistance = m_radius + other.m_radius;
		real centerDistance = glm::length(other.GetCenter() - m_center);
		real distance = centerDistance - radiusDistance;

		return IntersectData(centerDistance < radiusDistance, distance);
	}

}
