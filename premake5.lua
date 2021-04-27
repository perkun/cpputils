workspace "cpputils"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}"

project "cpputils"
	location "./"
	--possible values: ConsoleApp, SharedLib, StaticLib, Makefile, Utility, Packaging
	kind "StaticLib"

	language "C++"
	cppdialect "C++17"
	--buildoptions { "-pthread" }

	targetdir ("bin/" .. outputdir)
	objdir ("build/" .. outputdir)


	files
	{
		"src/Time/**.h",
		"src/Time/**.cpp"
	}

	includedirs
	{
	}

	links {}

	filter "configurations:Debug"
		symbols "On"
		defines "DEBUG"

	filter "configurations:Release"
		-- defines...
		optimize "On"
		defines "RELEASE"

	filter "configurations:Dist"
		-- defines...
		optimize "On"


project "test"
	location "./test/"
	--possible values: ConsoleApp, SharedLib, StaticLib, Makefile, Utility, Packaging
	kind "ConsoleApp"

	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir)
	objdir ("build/" .. outputdir)


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"src/Time/"
	}

	links { "cpputils" }

	filter "configurations:Debug"
		symbols "On"
		defines "DEBUG"

	filter "configurations:Release"
		-- defines...
		optimize "On"
		defines "RELEASE"

	filter "configurations:Dist"
		-- defines...
		optimize "On"
