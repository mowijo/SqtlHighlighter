cmake_minimum_required(VERSION 2.8)

PROJECT(libtokenizertest)
 
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release") 
	SET(CMAKE_BUILD_TYPE Debug) 
endif(NOT CMAKE_BUILD_TYPE STREQUAL "Release")

SET(CMAKE_CXX_FLAGS "-Wall")

FIND_PACKAGE( Qt4 REQUIRED )
set(CMAKE_AUTOMOC ON)

INCLUDE( ${QT_USE_FILE} )

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
TARGET_LINK_LIBRARIES( libtokenizertest ${QT_LIBRARIES} ${QT_QTTEST_LIBRARY} tokenizer)
ADD_CUSTOM_COMMAND(
    TARGET libtokenizertest POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/src/libtokenizer.dll ${CMAKE_BINARY_DIR}
)	
