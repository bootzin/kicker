#pragma once
#include "Core.h"

#ifndef INTERSECT_DATA_INCLUDED_H
#define INTERSECT_DATA_INCLUDED_H

namespace Kicker {

	class IntersectData
	{
	public:
		IntersectData(const bool doesIntersect, const real distance) : m_DoesIntersect(doesIntersect), m_Distance(distance) { }

		inline bool GetDoesIntersect() const { return m_DoesIntersect; }
		inline real GetDistance() const { return m_Distance; }
	private:
		const bool m_DoesIntersect;
		const real m_Distance;
	};

}

#endif // !INTERSECT_DATA_INCLUDED_H