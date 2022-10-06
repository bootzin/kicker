#include "ExportedFunctions.h"
#include "Kicker.h"
#include <glm/glm.hpp>
#include "kicker/BoundingSphere.h"

void Print() {

	Kicker::Log::Init();
	KCK_WARN("Logger Initialized!");
	KCK_INFO("This is a function call from Kicker!");

	Kicker::BoundingSphere sphere1(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
	Kicker::BoundingSphere sphere2(glm::vec3(0.0f, 3.0f, 0.0f), 1.0f);
	Kicker::BoundingSphere sphere3(glm::vec3(0.0f, 0.0f, 2.0f), 1.0f);
	Kicker::BoundingSphere sphere4(glm::vec3(1.0f, 0.0f, 0.0f), 1.0f);

	Kicker::IntersectData sphere1IntersectSphere2 = sphere1.IntersectBoundingSphere(sphere2);
	Kicker::IntersectData sphere1IntersectSphere3 = sphere1.IntersectBoundingSphere(sphere3);
	Kicker::IntersectData sphere1IntersectSphere4 = sphere1.IntersectBoundingSphere(sphere4);

	KCK_TRACE("Sphere 1 intersect sphere {}: {}, Distance: {}", 2, sphere1IntersectSphere2.GetDoesIntersect(), sphere1IntersectSphere2.GetDistance());
	KCK_TRACE("Sphere 1 intersect sphere {}: {}, Distance: {}", 3, sphere1IntersectSphere3.GetDoesIntersect(), sphere1IntersectSphere3.GetDistance());
	KCK_TRACE("Sphere 1 intersect sphere {}: {}, Distance: {}", 4, sphere1IntersectSphere4.GetDoesIntersect(), sphere1IntersectSphere4.GetDistance());
}
