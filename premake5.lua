-- premake5.lua
workspace "material"
	configurations { "Debug", "Release" }
	location "build"

project "material"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir "build/%{cfg.buildcfg}"
	includedirs { "../utils/src" }	
	includedirs { "../logger/src" }	
	includedirs { "../eilig/src" }	
	includedirs { "../basis/src" }	
	includedirs { "../node/src" }	
	includedirs { "../kdtree/src" }	
	includedirs { "../interpolation/src" }	
	includedirs { "../values/src" }
	includedirs { "../lua/include" }
	includedirs { "../sol2/include" }

	files { "src/**.hpp", "src/**.cpp" }

	filter "configurations:Debug"
		architecture "x86_64"     
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		architecture "x86_64"     
		defines { "NDEBUG" }
		optimize "Speed"