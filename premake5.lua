workspace "Pado"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "Pado/vendor/GLFW/include"

include "Pado/vendor/GLFW"

project "Pado"
	location "Pado"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "padopch.h"
	pchsource "Pado/src/padopch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PADO_PLATFORM_WINDOWS",
			"PADO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PADO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PADO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PADO_DIST"
		optimize "On"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Debug"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Dist"}
		buildoptions "/utf-8"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Pado/vendor/spdlog/include",
		"Pado/src"
	}

	links
	{
		"Pado"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PADO_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "PADO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PADO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PADO_DIST"
		optimize "On"

	filter {"system:windows", "configurations:Release"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Debug"}
		buildoptions "/utf-8"

	filter {"system:windows", "configurations:Dist"}
		buildoptions "/utf-8"
