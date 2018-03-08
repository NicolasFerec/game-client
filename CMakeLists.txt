cmake_minimum_required(VERSION 2.8)

# Déclaration du projet
project(game-client)

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/" ${CMAKE_MODULE_PATH})


# Génération de la liste des fichiers sources
file(
        GLOB_RECURSE
        source_files
        .
        src/*.cpp
)

find_package(SFML 2 COMPONENTS system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

# Déclaration de l'exécutable
add_executable(
        game-client
        ${source_files}
)

target_link_libraries(game-client ${SFML_LIBRARIES})