#include "ExportedFunctions.h"
#include "src/Kicker.h"

void Print() {

	Kicker::Log::Init();
	Kicker::Log::GetLogger()->warn("Logger Initialized!");
	Kicker::Log::GetLogger()->info("This is a function call from Kicker!");
}
