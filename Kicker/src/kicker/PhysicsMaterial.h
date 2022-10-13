#pragma once
#ifndef PHYSICS_MATERIAL_INCLUDED_H
#define PHYSICS_MATERIAL_INCLUDED_H

namespace Kicker
{
	class PhysicsMaterial
	{
	public:
		enum
		{
			COMBINE_AVERAGE,
			COMBINE_MINIMUM,
			COMBINE_MULTIPLY,
			COMBINE_MAXIMUM,
		};

		PhysicsMaterial(real dynamicFriction, real staticFriction, real bounciness, unsigned int frictionCombine, unsigned int bouncinessCombine) : 
			m_DynamicFriction(dynamicFriction), m_StaticFriction(staticFriction), m_Bounciness(bounciness), m_FrictionCombine(frictionCombine), m_BouncinessCombine(bouncinessCombine) { }

		inline const real GetDynamicFriction() const { return m_DynamicFriction; }
		inline const real GetStaticFriction() const { return m_StaticFriction; }
		inline const real GetBounciness() const { return m_Bounciness; }
		inline const unsigned int GetFrictionCombine() const { return m_FrictionCombine; }
		inline const unsigned int GetBouncinessCombine() const { return m_BouncinessCombine; }
	private:
		real m_DynamicFriction;
		real m_StaticFriction;
		real m_Bounciness;
		unsigned int m_FrictionCombine;
		unsigned int m_BouncinessCombine;
	};
}

#endif // !PHYSICS_MATERIAL_INCLUDED_H
