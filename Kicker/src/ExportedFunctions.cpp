#include "ExportedFunctions.h"
#include "Kicker.h"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/detail/type_mat4x4.hpp>

void Print() {

	Kicker::Log::Init();
	KCK_WARN("Logger Initialized!");
	KCK_INFO("This is a function call from Kicker!");
}
