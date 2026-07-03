workspace "桜 (Sakura)"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

filter "system:windows"
	staticruntime "off"
filter {}

flags {
	"MultiProcessorCompile"
}

buildoptions {
	"/utf-8"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "Vendor/GLFW/include"
IncludeDir["Glad"] = "Vendor/Glad/include"
IncludeDir["spdlog"] = "Vendor/spdlog/include"
IncludeDir["glm"] = "Vendor/glm"

include "Vendor/GLFW"
include "Vendor/Glad"

project "Sakura"
	location "Sakura"
	kind "StaticLib"
	language "C++"
	cppdialect "C++latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "spch.h"
	pchsource "Sakura/source/sakura/spch.cpp"

	files
	{
		"%{prj.name}/source/sakura/**.h",
		"%{prj.name}/source/sakura/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/source/sakura",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

	filter "configurations:Dist"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++latest"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"Sakura/Source"
	}

	externalincludedirs
	{
		"%{IncludeDir.spdlog}"
	}

	links
	{
		"Sakura"
	}

	filter "system:windows"
        systemversion "latest"
        buildoptions { "/external:I " .. _MAIN_SCRIPT_DIR .. "/Vendor/spdlog/include", "/external:W0" }
        ignoredefaultlibraries { "libcmt.lib" }

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

	filter "configurations:Dist"
		optimize "On"
