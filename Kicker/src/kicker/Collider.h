#pragma once
#ifndef COLLIDER_INCLUDED_H
#define COLLIDER_INCLUDED_H

#include "IntersectData.h"
#include "PhysicsMaterial.h"

namespace Kicker
{
	class Collider
	{
	public:
		Collider(const int type, const bool isTrigger, PhysicsMaterial* material) : m_Type(type), m_IsTrigger(isTrigger), m_Material(material) {}
		virtual ~Collider()
		{
			delete m_Material;
		}

		enum
		{
			TYPE_SPHERE,
			TYPE_AABB,

			TYPE_COUNT
		};

		IntersectData Intersect(const Collider& other);

		inline const int GetType() const { return m_Type; }
		inline const PhysicsMaterial* GetMaterial() const { return m_Material; }
		inline const bool GetIsTrigger() const { return m_IsTrigger; }
	private:
		int m_Type;
		PhysicsMaterial* m_Material;
		bool m_IsTrigger;
	};
}

#endif // !COLLIDER_INCLUDED_H

