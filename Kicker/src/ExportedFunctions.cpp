#include "ExportedFunctions.h"
#include "Kicker.h"
#include <glm/glm.hpp>

// Create
Kicker::PhysicsEngine* CreatePhysicsEngine()
{
	return new Kicker::PhysicsEngine();
}

Kicker::BoundingSphere* CreateBoundingSphere(glm::vec3 center, float radius)
{
	return new Kicker::BoundingSphere(center, radius);
}

Kicker::AABB* CreateAABB(glm::vec3 min, glm::vec3 max)
{
	return new Kicker::AABB(min, max);
}

Kicker::Plane* CreatePlane(glm::vec3 normal, float distance)
{
	return new Kicker::Plane(normal, distance);
}

Kicker::PhysicsObject* CreatePhysicsObject(glm::vec3 position, glm::vec3 velocity)
{
	return new Kicker::PhysicsObject(position, velocity);
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
void DeleteBoundingSphere(Kicker::BoundingSphere* sphere)
{
	delete sphere;
}

void DeleteAABB(Kicker::AABB* aabb)
{
	delete aabb;
}

void DeletePlane(Kicker::Plane* plane)
{
	delete plane;
}

void DeleteIntersect(Kicker::IntersectData* data)
{
	delete data;
}

void DeletePhysicsObject(Kicker::PhysicsObject* po)
{
	delete po;
}

void DeletePhysicsEngine(Kicker::PhysicsEngine* pe)
{
	delete pe;
}

// Physics Engine
void SimulatePhysicsEngine(Kicker::PhysicsEngine* physicsEngine, float deltaTime)
{
	physicsEngine->Simulate(deltaTime);
}

void AddPhysicsObjectToPhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::PhysicsObject* obj)
{
	physicsEngine->AddObject(obj);
}
