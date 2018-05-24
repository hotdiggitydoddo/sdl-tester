cmake_minimum_required(VERSION 3.10)
project(sdl_tester)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)
add_executable(sdl_tester main.cpp Game.cpp Game.h GameObject.cpp GameObject.h TextureManager.cpp TextureManager.h)
target_link_libraries(sdl_tester ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

