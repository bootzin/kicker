#pragma once

#include "PhysicsObject.h"
#include <vector>

namespace Kicker
{

	class PhysicsEngine
	{
	public:
		PhysicsEngine() { }

		void AddObject(PhysicsObject* obj);
		void Simulate(float delta);
	private:
		std::vector<PhysicsObject*> m_objects;
	};

}
