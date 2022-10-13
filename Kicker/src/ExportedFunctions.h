#pragma once

#include "kicker/BoundingSphere.h"
#include "kicker/Aabb.h"
#include "kicker/Plane.h"
#include "kicker/PhysicsObject.h"
#include "kicker/PhysicsEngine.h"
#include "kicker/PhysicsMaterial.h"
#include "kicker/Core.h"

extern "C" {

	// Create
	_declspec(dllexport) Kicker::PhysicsEngine* CreatePhysicsEngine();
	_declspec(dllexport) Kicker::BoundingSphere* CreateBoundingSphere(glm::vec3 center, Kicker::real radius, Kicker::PhysicsMaterial* material, bool isTrigger);
	_declspec(dllexport) Kicker::AABB* CreateAABB(glm::vec3 min, glm::vec3 max, Kicker::PhysicsMaterial* material, bool isTrigger);
	_declspec(dllexport) Kicker::Plane* CreatePlane(glm::vec3 normal, Kicker::real distance);
	_declspec(dllexport) Kicker::PhysicsObject* CreatePhysicsObject(glm::vec3 position, glm::vec3 velocity);

	// Intersections
	_declspec(dllexport) Kicker::IntersectData* IntersectsSphereSphere(Kicker::BoundingSphere* sphere1, Kicker::BoundingSphere* sphere2);
	_declspec(dllexport) Kicker::IntersectData* IntersectsAabbAabb(Kicker::AABB* aabb1, Kicker::AABB* aabb2);
	_declspec(dllexport) Kicker::IntersectData* IntersectsPlaneSphere(Kicker::Plane* plane, Kicker::BoundingSphere* sphere);

	// Delete
	_declspec(dllexport) void DeleteBoundingSphere(Kicker::BoundingSphere* sphere);
	_declspec(dllexport) void DeleteAABB(Kicker::AABB* aabb);
	_declspec(dllexport) void DeletePlane(Kicker::Plane* plane);
	_declspec(dllexport) void DeleteIntersect(Kicker::IntersectData* data);
	_declspec(dllexport) void DeletePhysicsObject(Kicker::PhysicsObject* po);
	_declspec(dllexport) void DeletePhysicsEngine(Kicker::PhysicsEngine* pe);

	// Physics Engine
	_declspec(dllexport) void SimulatePhysicsEngine(Kicker::PhysicsEngine* physicsEngine, float deltaTime);
	_declspec(dllexport) void AddPhysicsObjectToPhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::PhysicsObject* obj);
}