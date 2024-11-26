project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/HEngine/vendor/spdlog/include",
		"%{wks.location}/HEngine/src",
		"%{wks.location}/HEngine/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"HEngine"
	}

	filter "system:windows"
		systemversion "latest"

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
