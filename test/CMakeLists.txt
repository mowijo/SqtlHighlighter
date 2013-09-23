cmake_minimum_required(VERSION 2.8)

PROJECT(libtokenizertest)
 
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release") 
	SET(CMAKE_BUILD_TYPE Debug) 
endif(NOT CMAKE_BUILD_TYPE STREQUAL "Release")

SET(CMAKE_CXX_FLAGS "-Wall")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED) #For the tests
find_package(Qt5Test REQUIRED) #For the tests
set(CMAKE_AUTOMOC ON)


ADD_SUBDIRECTORY(../src src)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_BINARY_DIR}
) 

SET( SOURCES
    main.cpp
    TestSuite.cpp
    TokenTest.cpp
    TokenizerTest.cpp
)

ADD_EXECUTABLE( libtokenizertest ${SOURCES} )
TARGET_LINK_LIBRARIES( libtokenizertest tokenizer)

qt5_use_modules(libtokenizertest Widgets)
qt5_use_modules(libtokenizertest Gui)	#For the tests
qt5_use_modules(libtokenizertest Test)	#For the tests
