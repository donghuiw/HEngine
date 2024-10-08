workspace "HEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "HEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "HEngine/vendor/Glad/include"

include "HEngine/vendor/GLFW"
include "HEngine/vendor/Glad"

project "HEngine"
	location "HEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hepch.h"
	pchsource "HEngine/src/hepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{prj.name}/vendor/spdlog/include"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
				"HE_PLATFORM_WINDOWS",
				"HE_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			"{COPYDIR} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir ..  "/SandBox/\"" 
			--xcopy /Q /E /Y /I ..\bin\Debug-windows-x86_64\HEngine\HEngine.dll ..\bin\Debug-windows-x86_64\SandBox\
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "HE_DIST"
		buildoptions "/MD"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"HEngine/vendor/spdlog/include",
		"HEngine/src"
	}

	links
	{
		"HEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
				"HE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
	defines "HE_RELEASE"
	buildoptions "/MD"
	optimize "On"

	filter "configurations:Dist"
	defines "HE_DIST"
	buildoptions "/MD"
	optimize "On"