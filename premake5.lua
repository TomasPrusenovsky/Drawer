workspace "Drawer"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Drawer"
	location "Drawer"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/"..outputdir.."/%{prj.name}")
	objdir ("bin-int/"..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
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