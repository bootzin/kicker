#include "ExportedFunctions.h"
#include <glm/glm.hpp>

// Create
Kicker::PhysicsEngine* CreatePhysicsEngine()
{
	return new Kicker::PhysicsEngine();
}

Kicker::Plane* CreatePlane(glm::vec3 normal, Kicker::real distance)
{
	return new Kicker::Plane(normal, distance);
}

// Intersect
Kicker::IntersectData* IntersectsSphereSphere(Kicker::BoundingSphere* sphere1, Kicker::BoundingSphere* sphere2)
{
	Kicker::IntersectData data = sphere1->IntersectBoundingSphere(*sphere2);
	return new Kicker::IntersectData(data.GetDoesIntersect(), data.GetDistance());
}

Kicker::IntersectData* IntersectsAabbAabb(Kicker::AABB* aabb1, Kicker::AABB* aabb2)
{
	Kicker::IntersectData data = aabb1->IntersectAABB(*aabb2);
	return new Kicker::IntersectData(data.GetDoesIntersect(), data.GetDistance());
}

Kicker::IntersectData* IntersectsPlaneSphere(Kicker::Plane* plane, Kicker::BoundingSphere* sphere)
{
	Kicker::IntersectData data = plane->IntersectSphere(*sphere);
	return new Kicker::IntersectData(data.GetDoesIntersect(), data.GetDistance());
}

// Delete
void DeletePlane(Kicker::Plane* plane)
{
	delete plane;
}

void DeleteIntersect(Kicker::IntersectData* data)
{
	delete data;
}

void DeletePhysicsEngine(Kicker::PhysicsEngine* pe)
{
	delete pe;
}

// Physics Engine
void SimulatePhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::real deltaTime)
{
	physicsEngine->Simulate(deltaTime);
}

void AddParticleToPhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::Particle* obj)
{
	physicsEngine->AddObject(obj);
}

void RemoveParticleFromPhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::Particle* obj)
{
	physicsEngine->RemoveObject(obj);
}
