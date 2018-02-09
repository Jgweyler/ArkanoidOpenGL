local project_names = {
"Arkanoid"
}

local function new_project( name )
	project (name)
		kind ("ConsoleApp")
		includedirs{"include", "src/deps/glfw", "src/deps/glad", "src/deps/stb" }
		files {"tests/"..name.."/*.cpp",
			   "src/"..name.."/*.h",
			   "src/*.cpp",
			   "src/geometries/*.cpp",
			   "src/gameObjects/*.cpp";
			   "include/**.h",
			   "src/deps/glfw/context.c",
			   "src/deps/glfw/init.c",
			   "src/deps/glfw/input.c",
			   "src/deps/glfw/monitor.c",
			   "src/deps/glfw/window.c",
			   "src/deps/glfw/vulkan.c",
			   "src/deps/glad/glad.c",
			   "src/deps/stb/*"}
		defines {"_GLFW_USE_OPENGL=1"}
		vpaths { ["Headers"] = "include/*.h",
				 ["Headers/geometries"] =  "include/geometries/*.h",
				 ["Headers/gameObjects"] =  "include/gameObjects/*.h",
				 ["Source"]  =  "src/*.cpp",
				 ["Source/geometries"] = "src/geometries/*.cpp",
				 ["Source/gameObjects"] = "src/gameObjects/*.cpp",
				 ["Deps Headers"] = {"include/GLFW/*.h",
				                    "include/glad/**",
				                	"include/KHR/**",
				                	"include/glm/**"},
				 ["Deps Src"] = "src/deps/**",
				 ["Tests"] = "tests/"..name.."/*.cpp"}
		configuration {"debug"}
			flags {"Symbols"}
			targetsuffix("_d")
		configuration {"release"}
			flags {"Optimize"}
			targetsuffix("_r")
		configuration {"windows"}
			files{"src/deps/glfw/egl_context.c",
				  "src/deps/glfw/win32*",
				  "src/deps/glfw/wgl_*",
				  "src/deps/glfw/winmm_*"}
			links{"OpenGL32"}
			defines{"_GLFW_WIN32", "_GLFW_WGL"}
			flags{"NoEditAndContinue"}
			windowstargetplatformversion "10.0.16299.0"
end

solution "Arkanoid"
	configurations {"debug", "release"}
	language("c++")
	platforms{"x64"}
	location("build")
	debugdir("build")
	targetdir("bin")
	flags{"ExtraWarnings"}

for index, name in pairs(project_names) do
	print(index,name);
  new_project(name)
end