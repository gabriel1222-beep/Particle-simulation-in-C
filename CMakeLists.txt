cmake_minimum_required(VERSION 3.21)
project(sdl2_app LANGUAGES C)
file(GLOB_RECURSE SRC_PATH CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wdouble-promotion -Wformat=2 -Wundef -Werror -fsanitize=address -g")
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
add_executable(sdl2_app ${SRC_PATH})
     target_include_directories(sdl2_app PUBLIC include/)

target_link_libraries(sdl2_app PRIVATE
     $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
  $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
  $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)


