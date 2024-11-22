workspace "SecondChance"
    configurations { "Debug", "Release" }

-- project "Maths"
--     kind "StaticLib"
--     language "C"
--     targetdir "bin/%{cfg.buildcfg}"
    
--     filter "configurations:Debug"
--         runtime "Debug"
--         symbols "On"
        
--     filter "configurations:Release"
--         runtime "Release"
--         optimize "On"
    
--     prebuildcommands { "odin build src/maths/maths.odin -file -build-mode:obj -out:bin/%{cfg.buildcfg}/maths.obj" }


project "CppApp"
    platforms {"x64"}
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    
    files { "src/**.cpp", "src/**.h" }
    includedirs { "include" }
    libdirs { "lib", "lib/glfw.dll" }
    links { "glew32d", "glfw3", "opengl32" }
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        
    filter "configurations:Release"
        runtime "Release"
        optimize "On"
        