cmake_minimum_required(VERSION 3.5)
project(unimpressive_game_framework)

#help
#message("Unimpressve Game Framework, cmake useful options:")
#message("-DBUILD_EXAMPLES=ON to build examples")
#message("-DBUILD_SHARED=ON to build shared library")

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -O2")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

# Find OpenGL
#find_package(OpenGL REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIR})

#Find GLEW
#find_package(GLEW 1.12 REQUIRED)
#include_directories(${GLEW_INCLUDE_PATH})
#
##Find LetThereBeTheLight 2
#find_library(LTBL NAMES ltbl LTBL)
#
##Find TMX-loader
#find_library(TMX_LOADER NAMES tmx-loader tmx)
#include_directories("~/Libs/include/")

# Find SFML
find_package(SFML 2.0 REQUIRED system window graphics network audio)

include_directories(${SFML_INCLUDE_DIR})
#Find Box2d
find_package(Box2d 2.3 REQUIRED)
include_directories(${BOX2D_INCLUDE_DIR})

#C++14
SET(CMAKE_CXX_FLAGS "-std=c++1y -O2 -D__NO_INLINE__ -static-libstdc++ -static -static-libgcc")


# Project
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# -DUGF_BUILD_EXAMPLES=ON to build examples
if(BUILD_EXAMPLES)
	add_subdirectory("examples")
        message("- Will build examples")
endif(BUILD_EXAMPLES)

#Just a helper for QtCreator to display .h files in the project
file(GLOB INCLUDE_UGF include/UGF/*.h include/UGF/*/*.h)

set(SRC_UGF
        src/UGF/Framecounter.cpp
        src/UGF/IniFile.cpp
        src/UGF/Exeptions/IniExeptions.cpp
#        src/UGF/ActorsSystem.cpp
        src/UGF/Actor.cpp
        src/UGF/Taggable.cpp
#        src/UGF/ActorsFactory.cpp
        src/UGF/ParticleSystem.cpp
        src/UGF/BitmapFont.cpp
        src/UGF/Text.cpp
        src/UGF/ResourceManager.cpp
)

include_directories("include")
include_directories(".")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#System installed libs
#include_directories("~/Libs/include/")
#include_directories("/usr/include/")
#include_directories("/usr/local/include/")

set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib ${BOX2D_LIBRARY} lib/ ~/Library/Frameworks/lib/)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/ ~/Libs/lib/)

message("Current Source Dir:")
message(${CMAKE_CURRENT_SOURCE_DIR})

add_library (ugf ${SRC_UGF} ${INCLUDE_UGF})
target_include_directories (ugf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(ugf ${SFML_LIBRARIES} ${OPENGL_LIBRARIES} ${BOX2D_LIBRARY})
