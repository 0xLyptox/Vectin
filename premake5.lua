workspace "Vectin"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}

group ""

project "Vectin"
	location "Vectin"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vnpch.h"
	pchsource "Vectin/src/vnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	postbuildcommands {
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VN_BUILD_DLL",
			"VN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VN_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Vectin/vendor/spdlog/include",
		"Vectin/src",
		"Vectin/vendor"
	}

	links
	{
		"Vectin"
	}

	filter "system:windows"
		systemversion "latest"
		
		defines
		{
			"VN_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "VN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VN_DIST"
		runtime "Release"
		optimize "on"