project "DorekEngine"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Dorek/vendor/spdlog/include",
		"%{wks.location}/Dorek/src",
		"%{wks.location}/Dorek/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
	}

	links
	{
		"Dorek"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "DK_DEBUG"
		runtime "Debug"
		symbols "on"
		
		postbuildcommands
		{
			"{COPYDIR} \"%{LibraryDir.VulkanSDK_DebugDLL}\" \"%{cfg.targetdir}\""
		}

	filter "configurations:Release"
		defines "DK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DK_DIST"
		runtime "Release"
		optimize "on"
