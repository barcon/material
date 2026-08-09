-- premake5.lua
workspace "material"
	configurations { "Debug", "Release", "ReleaseCL"  }
	location "build"

project "material"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	architecture "x86_64"
	objdir "%{cfg.location}/obj/%{cfg.platform}_%{cfg.buildcfg}"	

	targetdir "build/%{cfg.buildcfg}"
	includedirs { "../utils/src" }	
	includedirs { "../logger/src" }	
	includedirs { "../eilig/src" }	
	includedirs { "../basis/src" }	
	includedirs { "../node/src" }	
	includedirs { "../kdtree/src" }	
	includedirs { "../interpolation/src" }	
	includedirs { "../value/src" }

	files { "src/**.hpp", "src/**.cpp" }

	filter "configurations:Debug"  
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"    
		defines { "NDEBUG" }
		optimize "Speed"

	filter "configurations:ReleaseCL"   
		defines { "NDEBUG", "EILIG_ENABLE_OPENCL" }
		optimize "Speed"	
		
		includedirs { "../club/src" }	
		includedirs { "../opencl/inc" }