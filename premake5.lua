workspace "Kicker"
	architecture "x64"

	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["glm"] = "Kicker/vendor/glm"

project "Kicker"
	location "Kicker"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kckpch.h"
	pchsource "Kicker/src/kckpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glm}"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"KCK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KCK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "KCK_RELEASE"
		optimize "On"