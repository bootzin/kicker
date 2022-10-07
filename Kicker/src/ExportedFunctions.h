#pragma once

#include "kicker/BoundingSphere.h"
#include "kicker/Aabb.h"
#include "kicker/Plane.h"
#include "kicker/PhysicsObject.h"

extern "C" {

	//Create Colliders
	_declspec(dllexport) Kicker::BoundingSphere* CreateBoundingSphere(glm::vec3 center, float radius);
	_declspec(dllexport) Kicker::AABB* CreateAABB(glm::vec3 min, glm::vec3 max);
	_declspec(dllexport) Kicker::Plane* CreatePlane(glm::vec3 normal, float distance);
	_declspec(dllexport) Kicker::PhysicsObject* CreatePhysicsObject(glm::vec3 position, glm::vec3 velocity);

	//Intersections
	_declspec(dllexport) Kicker::IntersectData* IntersectsSphereSphere(Kicker::BoundingSphere* sphere1, Kicker::BoundingSphere* sphere2);
	_declspec(dllexport) Kicker::IntersectData* IntersectsAabbAabb(Kicker::AABB* aabb1, Kicker::AABB* aabb2);
	_declspec(dllexport) Kicker::IntersectData* IntersectsPlaneSphere(Kicker::Plane* plane, Kicker::BoundingSphere* sphere);

	//Delete Colliders
	_declspec(dllexport) void DeleteBoundingSphere(Kicker::BoundingSphere* sphere);
	_declspec(dllexport) void DeleteAABB(Kicker::AABB* aabb);
	_declspec(dllexport) void DeletePlane(Kicker::Plane* plane);
	_declspec(dllexport) void DeleteIntersect(Kicker::IntersectData* data);
	_declspec(dllexport) void DeletePhysicsObject(Kicker::PhysicsObject* po);

	_declspec(dllexport) void Integrate(Kicker::PhysicsObject* obj, float deltaTime);
}