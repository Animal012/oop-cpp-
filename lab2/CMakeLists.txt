cmake_minimum_required(VERSION 3.23)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

set (PROJECT_HEADERS
        classes.h)

set (PROJECT_SOURCES
        main.cpp
        planet/library.cpp
        shop/shop.cpp)

add_executable(lab2 main.cpp planet/library.cpp shop/shop.cpp)

add_subdirectory(planet)
add_subdirectory(shop)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/planet.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shop.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_link_libraries(${project} planet)
target_link_libraries(shop ${CMAKE_THREAD_LIBS_INIT})

IF (NOT WIN32)
target_link_libraries(lab2 m)
ENDIF()