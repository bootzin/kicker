#pragma once

#ifndef INTERSECT_DATA_INCLUDED_H
#define INTERSECT_DATA_INCLUDED_H

namespace Kicker {

	class IntersectData
	{
	public:
		IntersectData(const bool doesIntersect, const float distance) : m_DoesIntersect(doesIntersect), m_Distance(distance) { }

		inline bool GetDoesIntersect() const { return m_DoesIntersect; }
		inline float GetDistance() const { return m_Distance; }
	private:
		const bool m_DoesIntersect;
		const float m_Distance;
	};

}

#endif // !INTERSECT_DATA_INCLUDED_H