workspace "Drawer"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Drawer/vendor/GLFW/include"

group "Dependencies"
	include "Drawer/vendor/GLFW"

group ""

project "Drawer"
	location "Drawer"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	pchheader "dwpch.hpp"
	pchsource "Drawer/src/dwpch.cpp"

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
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
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DW_PLATFORM_WINDOWS",
			"DW_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DW_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/".. outputdir .."/%{prj.name}")
	objdir ("bin-int/".. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Drawer/vendor/spdlog/include",
		"Drawer/src"
	}

	links
	{
		"Drawer"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DW_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DW_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DW_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DW_DIST"
		optimize "On"
