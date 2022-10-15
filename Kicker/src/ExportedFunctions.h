#pragma once

#include "kicker/BoundingSphere.h"
#include "kicker/Aabb.h"
#include "kicker/Plane.h"
#include "kicker/Particle.h"
#include "kicker/PhysicsEngine.h"
#include "kicker/PhysicsMaterial.h"
#include "kicker/Core.h"

extern "C" {

	// Create
	_declspec(dllexport) Kicker::PhysicsEngine* CreatePhysicsEngine();
	_declspec(dllexport) Kicker::Plane* CreatePlane(glm::vec3 normal, Kicker::real distance);

	// Intersections
	_declspec(dllexport) Kicker::IntersectData* IntersectsSphereSphere(Kicker::BoundingSphere* sphere1, Kicker::BoundingSphere* sphere2);
	_declspec(dllexport) Kicker::IntersectData* IntersectsAabbAabb(Kicker::AABB* aabb1, Kicker::AABB* aabb2);
	_declspec(dllexport) Kicker::IntersectData* IntersectsPlaneSphere(Kicker::Plane* plane, Kicker::BoundingSphere* sphere);

	// Delete
	_declspec(dllexport) void DeletePlane(Kicker::Plane* plane);
	_declspec(dllexport) void DeleteIntersect(Kicker::IntersectData* data);
	_declspec(dllexport) void DeletePhysicsEngine(Kicker::PhysicsEngine* pe);

	// Physics Engine
	_declspec(dllexport) void SimulatePhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::real deltaTime);
	_declspec(dllexport) void AddParticleToPhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::Particle* obj);
	_declspec(dllexport) void RemoveParticleFromPhysicsEngine(Kicker::PhysicsEngine* physicsEngine, Kicker::Particle* obj);
}