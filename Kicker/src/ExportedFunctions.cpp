#include "ExportedFunctions.h"
#include "Kicker.h"
#include <glm/glm.hpp>

void Integrate(Kicker::PhysicsObject* obj, float deltaTime)
{
	obj->Integrate(deltaTime);
}

// Create
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

//void Print() {
//
//	Kicker::Log::Init();
//	KCK_WARN("Logger Initialized!");
//	KCK_INFO("This is a function call from Kicker!");
//
//	Kicker::BoundingSphere sphere1(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
//	Kicker::BoundingSphere sphere2(glm::vec3(0.0f, 3.0f, 0.0f), 1.0f);
//	Kicker::BoundingSphere sphere3(glm::vec3(0.0f, 0.0f, 2.0f), 1.0f);
//	Kicker::BoundingSphere sphere4(glm::vec3(1.0f, 0.0f, 0.0f), 1.0f);
//
//	Kicker::IntersectData sphere1IntersectSphere2 = sphere1.IntersectBoundingSphere(sphere2);
//	Kicker::IntersectData sphere1IntersectSphere3 = sphere1.IntersectBoundingSphere(sphere3);
//	Kicker::IntersectData sphere1IntersectSphere4 = sphere1.IntersectBoundingSphere(sphere4);
//
//	KCK_TRACE("Sphere 1 intersect sphere {}: {}, Distance: {}", 2, sphere1IntersectSphere2.GetDoesIntersect(), sphere1IntersectSphere2.GetDistance());
//	KCK_TRACE("Sphere 1 intersect sphere {}: {}, Distance: {}", 3, sphere1IntersectSphere3.GetDoesIntersect(), sphere1IntersectSphere3.GetDistance());
//	KCK_TRACE("Sphere 1 intersect sphere {}: {}, Distance: {}\n", 4, sphere1IntersectSphere4.GetDoesIntersect(), sphere1IntersectSphere4.GetDistance());
//
//	Kicker::AABB aabb1(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//	Kicker::AABB aabb2(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(2.0f, 2.0f, 2.0f));
//	Kicker::AABB aabb3(glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(2.0f, 1.0f, 1.0f));
//	Kicker::AABB aabb4(glm::vec3(0.0f, 0.0f, -2.0f), glm::vec3(1.0f, 1.0f, -1.0f));
//	Kicker::AABB aabb5(glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 1.5f, 1.0f));
//
//	Kicker::IntersectData aabb1Intersectsaabb2 = aabb1.IntersectAABB(aabb2);
//	Kicker::IntersectData aabb1Intersectsaabb3 = aabb1.IntersectAABB(aabb3);
//	Kicker::IntersectData aabb1Intersectsaabb4 = aabb1.IntersectAABB(aabb4);
//	Kicker::IntersectData aabb1Intersectsaabb5 = aabb1.IntersectAABB(aabb5);
//
//	KCK_TRACE("AABB 1 intersect AABB {}: {}, Distance: {}", 2, aabb1Intersectsaabb2.GetDoesIntersect(), aabb1Intersectsaabb2.GetDistance());
//	KCK_TRACE("AABB 1 intersect AABB {}: {}, Distance: {}", 3, aabb1Intersectsaabb3.GetDoesIntersect(), aabb1Intersectsaabb3.GetDistance());
//	KCK_TRACE("AABB 1 intersect AABB {}: {}, Distance: {}", 4, aabb1Intersectsaabb4.GetDoesIntersect(), aabb1Intersectsaabb4.GetDistance());
//	KCK_TRACE("AABB 1 intersect AABB {}: {}, Distance: {}\n", 5, aabb1Intersectsaabb5.GetDoesIntersect(), aabb1Intersectsaabb5.GetDistance());
//
//	Kicker::Plane plane1(glm::vec3(0.f, 1.f, 0.f), 0.f);
//
//	Kicker::IntersectData plane1IntersectsSphere1 = plane1.IntersectSphere(sphere1);
//	Kicker::IntersectData plane1IntersectsSphere2 = plane1.IntersectSphere(sphere2);
//	Kicker::IntersectData plane1IntersectsSphere3 = plane1.IntersectSphere(sphere3);
//	Kicker::IntersectData plane1IntersectsSphere4 = plane1.IntersectSphere(sphere4);
//
//	KCK_TRACE("Plane 1 intersect Sphere {}: {}, Distance: {}", 1, plane1IntersectsSphere1.GetDoesIntersect(), plane1IntersectsSphere1.GetDistance());
//	KCK_TRACE("Plane 1 intersect Sphere {}: {}, Distance: {}", 2, plane1IntersectsSphere2.GetDoesIntersect(), plane1IntersectsSphere2.GetDistance());
//	KCK_TRACE("Plane 1 intersect Sphere {}: {}, Distance: {}", 3, plane1IntersectsSphere3.GetDoesIntersect(), plane1IntersectsSphere3.GetDistance());
//	KCK_TRACE("Plane 1 intersect Sphere {}: {}, Distance: {}\n", 4, plane1IntersectsSphere4.GetDoesIntersect(), plane1IntersectsSphere4.GetDistance());
//}
