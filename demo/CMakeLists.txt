cmake_minimum_required(VERSION 2.8.8)

PROJECT(SqlHighlighterDemo)
 
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release") 
	SET(CMAKE_BUILD_TYPE Debug) 
endif(NOT CMAKE_BUILD_TYPE STREQUAL "Release")

SET(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")


ADD_SUBDIRECTORY(../src src)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_BINARY_DIR}
) 

SET( SOURCES
    main.cpp
)

ADD_EXECUTABLE( demo ${SOURCES} )
TARGET_LINK_LIBRARIES( demo tokenizer )
qt5_use_modules(demo Widgets)
