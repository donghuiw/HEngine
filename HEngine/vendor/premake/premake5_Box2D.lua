local premakeDir = path.getabsolute(".")
local projectDir = path.getabsolute("../Box2D")
os.chdir(projectDir)

project "Box2D"
	kind "StaticLib"
	language "C"
	cdialect  "C17"
	staticruntime "off"
	visibility "Hidden" -- gcc compile option
	warnings "off" -- Òþ²ØÒ»Ð©±àÒë¾¯¸æ

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.c",
		"src/**.h",
		"include/**.h",
	}

	includedirs
	{
		"include",
	}

	filter { "system:windows", "action:vs*" }
		buildoptions { "/experimental:c11atomics" }

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"
		-- targetsuffix "_d"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
        symbols "off"