workspace "Slateback"
	architecture "x64"
	startproject "SlatebackAppCLI"

	configurations
	{
		"Debug",
		"Release",
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["slateback"] = "Slateback/include"
IncludeDir["cereal"] = "Dependencies/cereal/include/"

project "Slateback"
	location "Slateback"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")



	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/include/**.h",
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		".",
		"Slateback/",
		"%{IncludeDir.cereal}"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

	filter "configurations:vs2019"
		pchheader "slatebackpch.h"
		pchsource "Slateback/slatebackpch.cpp"

project "SlatebackAppCLI"
	location "SlatebackAppCLI"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	targetname ("slt")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	includedirs
	{
		".",
		"%{IncludeDir.slateback}",
		"%{IncludeDir.cereal}",
		"%{prj.name}"
	}

	links
	{
		"Slateback"
	}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

		filter "configurations:vs2019"
			pchheader "SlatebackAppCLI/sltcli_pch.h"
			pchsource "SlatebackAppCLI/sltcli_pch.cpp"
