include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "HEngine"
	architecture "x86_64"
	startproject "SandBox"

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
	include "HEngine/vendor/GLFW"
	include "HEngine/vendor/Glad"
	include "HEngine/vendor/imgui"
	include "HEngine/vendor/yaml-cpp"

group ""

include "HEngine"
include "Sandbox"
include "HEngine-Editor"