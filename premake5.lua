workspace "HEngine"
	architecture "x64"
	startproject "SandBox"

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
IncludeDir["ImGui"] = "HEngine/vendor/imgui"
IncludeDir["glm"] = "HEngine/vendor/glm"

include "HEngine/vendor/GLFW"
include "HEngine/vendor/Glad"
include "HEngine/vendor/imgui"

project "HEngine"
	location "HEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hepch.h"
	pchsource "HEngine/src/hepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{prj.name}/vendor/spdlog/include"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
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
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HE_DIST"
		runtime "Release"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"HEngine/src",
		"HEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"HEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
				"HE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HE_DIST"
		runtime "Release"
		optimize "On"