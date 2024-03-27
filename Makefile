
# "args": [
#    "${workspaceFolder}\\src\\*.cpp",
#    "-std=c++20",
#    "${workspaceFolder}\\*.cpp",
#    "-o",
#    "${fileDirname}\\main.exe",
#    "-Wall",
#    "-Wno-missing-braces",
#    "-g",
#    "-O0",
#    "C:/raylib/raylib/src/raylib.rc.data",
#    "-I.",
#    "-IC:/raylib/raylib/src",
#    "-IC:/raylib/raylib/src/external",
#    "-L.",
#    "-LC:/raylib/raylib/src",
#    "-lraylib",
#    "-lopengl32",
#    "-lgdi32",
#    "-lwinmm"

debug:
	g++ main.cpp -o main.exe -Wall -std=c++20 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

