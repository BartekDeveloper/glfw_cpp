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
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    
    files { "src/**.cpp", "src/**.h" }
    includedirs { "include" }
    -- links { "Maths" }
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        
    filter "configurations:Release"
        runtime "Release"
        optimize "On"