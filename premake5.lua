include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Dorek"
	architecture "x86_64"
	startproject "DorekEngine"

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
	include "Dorek/vendor/GLFW"
	include "Dorek/vendor/Glad"
	include "Dorek/vendor/imgui"
	include "Dorek/vendor/yaml-cpp"
group ""

include "Dorek"
include "Sandbox"
include "DorekEngine"
