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

group ""
project "Slateback"
	location "Slateback"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "slatebackpch.h"
	pchsource "Slateback/slatebackpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/include/**.h",
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
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
		
project "SlatebackAppCLI"
	location "SlatebackAppCLI"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"
	
	pchheader "sltcli_pch.h"
	pchsource "SlatebackAppCLI/sltcli_pch.cpp"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	targetname ("slt")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs
	{
		".",
		"%{IncludeDir.slateback}",
		"%{IncludeDir.cereal}"
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