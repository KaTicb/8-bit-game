cmake_minimum_required(VERSION 3.24)
project(game VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)


set(LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/libraries)
set(COMPILED_LIBRARIES ${CMAKE_CURRENT_BINARY_DIR}/libraries)


include_directories(${CMAKE_CURRENT_LIST_DIR})


# SFML library import
add_subdirectory(${LIBRARIES}/SFML)
include_directories(${LIBRARIES}/SFML/include)


add_executable(${PROJECT_NAME} main.cpp Move.cpp Move.h Shoot.cpp Shoot.h)
target_link_libraries(${PROJECT_NAME}
                    sfml-system
                    sfml-window
                    sfml-graphics
                    sfml-audio
                    )

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${COMPILED_LIBRARIES}/SFML/lib/ ${CMAKE_CURRENT_BINARY_DIR}/)