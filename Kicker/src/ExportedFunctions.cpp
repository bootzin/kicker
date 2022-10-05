#include "ExportedFunctions.h"
#include "Kicker.h"
#include "kckpch.h"

void Print() {

	Kicker::Log::Init();
	Kicker::Log::GetLogger()->warn("Logger Initialized!");
	Kicker::Log::GetLogger()->info("This is a function call from Kicker!");
}
