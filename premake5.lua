include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "HEngine"
	architecture "x86_64"
	startproject "HEngine-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	solution_items
	{
		".editorconfig"
	}
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


group "Dependencies"
	include "vendor/premake"
	include "HEngine/vendor/premake/premake5_GLFW.lua"
	include "HEngine/vendor/Glad"
	include "HEngine/vendor/premake/premake5_imgui.lua"
	include "HEngine/vendor/premake/premake5_yaml.lua"
	include "HEngine/vendor/premake/premake5_Box2D.lua"

group ""

group "Core"
	include "HEngine"
	include "HEngine-ScriptCore"

group ""

group "Tools"
	include "HEngine-Editor"

group ""

group "Misc"
	include "Sandbox"

group ""