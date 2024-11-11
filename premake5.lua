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
IncludeDir["stb_image"] = "HEngine/vendor/stb_image"

group "Dependencies"
	include "HEngine/vendor/GLFW"
	include "HEngine/vendor/Glad"
	include "HEngine/vendor/imgui"

project "HEngine"
	location "HEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hepch.h"
	pchsource "HEngine/src/hepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
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
		systemversion "latest"

		defines
		{
				"HE_PLATFORM_WINDOWS",
				"HE_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HE_DIST"
		runtime "Release"
		optimize "on"

project "SandBox"
	location "SandBox"
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
		systemversion "latest"

		defines
		{
			"HE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HE_DIST"
		runtime "Release"
		optimize "on"
		