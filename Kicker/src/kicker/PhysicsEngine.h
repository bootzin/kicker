#pragma once

#ifndef PHYSICS_ENGINE_INCLUDED_H
#define PHYSICS_ENGINE_INCLUDED_H

#include "PhysicsObject.h"
#include <vector>

namespace Kicker
{

	class PhysicsEngine
	{
	public:
		PhysicsEngine() {}

		void AddObject(PhysicsObject* obj);
		void Simulate(float delta);
	private:
		std::vector<PhysicsObject*> m_objects;
	};

}
#endif // !PHYSICS_ENGINE_INCLUDED_H

