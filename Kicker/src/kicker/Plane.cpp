#include "kckpch.h"
#include "Plane.h"

namespace Kicker {

    Plane Plane::Normalized() const
    {
        float magnitude = glm::length(m_normal);

        return Plane(m_normal / magnitude, m_distance / magnitude);
    }

    IntersectData Plane::IntersectSphere(const BoundingSphere& other) const
    {
        float distanceFromSphereCenter = fabs(glm::dot(m_normal, other.GetCenter()) + m_distance);
        float distanceFromSphere = distanceFromSphereCenter - other.GetRadius();

        return IntersectData(distanceFromSphere < 0, distanceFromSphere);
    }
}
