#include "kckpch.h"
#include "Collider.h"
#include "BoundingSphere.h"
#include "AABB.h"

namespace Kicker
{
	IntersectData Collider::Intersect(const Collider& other)
	{
		switch (m_Type)
		{
		case TYPE_AABB:
			switch (other.GetType())
			{
			case TYPE_AABB:
				((AABB*)this)->IntersectAABB((AABB&)other);
				break;
			case TYPE_SPHERE:
				break;
			default:
				break;
			}
			break;
		case TYPE_SPHERE:
			switch (other.GetType())
			{
			case TYPE_AABB:
				break;
			case TYPE_SPHERE:
				return ((BoundingSphere*)this)->IntersectBoundingSphere((BoundingSphere&)other);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}

		return IntersectData(false, -999999);
	}
}
