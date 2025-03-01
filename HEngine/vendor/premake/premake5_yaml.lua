local premakeDir = path.getabsolute(".")
local projectDir = path.getabsolute("../yaml-cpp")
os.chdir(projectDir)

project "yaml-cpp"
	kind "StaticLib"
	language "C++"
	warnings "off" -- 隐藏一些编译警告

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
		
		"include/**.h"
	}

	includedirs
	{
		"include"
	}

	defines
	{
		"YAML_CPP_STATIC_DEFINE"
	}

	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "off"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

os.chdir(premakeDir)