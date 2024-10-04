workspace "HEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HEngine"
	location "HEngine"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.26100.0"

		defines
		{
				"HE_PLATFORM_WINDOWS",
				"HE_BUILD_DLL"
		}

		postbuildcommands
		{
			"{COPYDIR} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir ..  "/SandBox/\"" 
			--xcopy /Q /E /Y /I ..\bin\Debug-windows-x86_64\HEngine\HEngine.dll ..\bin\Debug-windows-x86_64\SandBox\
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HE_DIST"
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
		systemversion "10.0.26100.0"

		defines
		{
				"HE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HE_DEBUG"
		symbols "On"

	filter "configurations:Release"
	defines "HE_RELEASE"
	optimize "On"

	filter "configurations:Dist"
	defines "HE_DIST"
	optimize "On"