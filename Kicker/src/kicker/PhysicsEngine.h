#pragma once

#ifndef PHYSICS_ENGINE_INCLUDED_H
#define PHYSICS_ENGINE_INCLUDED_H

#include "Particle.h"
#include <vector>

namespace Kicker
{

	class PhysicsEngine
	{
	public:
		PhysicsEngine() {}

		void AddObject(Particle* obj);
		void RemoveObject(Particle* obj);
		void Simulate(real delta);
	private:
		std::vector<Particle*> m_Particles;
	};

}
#endif // !PHYSICS_ENGINE_INCLUDED_H

