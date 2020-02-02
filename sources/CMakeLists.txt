cmake_minimum_required(VERSION 3.0)

project(PacMan)

set(SOURCE_EXE PacManProj.cpp)
set(SOURCE_LIB Blinky.cpp
	GameField.cpp Ghost.cpp
	Inky.cpp Klayd.cpp
	MainClass.cpp MainMenu.cpp
	PacMan.cpp Pinky.cpp
	Render.cpp StateMachine.cpp)

add_library(liba STATIC ${SOURCE_LIB})

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(PacMan ${SOURCE_EXE})

target_link_libraries(PacMan liba)