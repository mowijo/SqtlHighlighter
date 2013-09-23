cmake_minimum_required(VERSION 2.8.8)

#
# cmd /c quex -i sql.qx -o sqllexer --source-package quex
#

PROJECT(libtokenizer)
 
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release") 
	SET(CMAKE_BUILD_TYPE Debug) 
endif(NOT CMAKE_BUILD_TYPE STREQUAL "Release")

SET(CMAKE_CXX_FLAGS "-Wall")
add_definitions(-DQUEX_OPTION_ASSERTS_DISABLED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_BIR})

find_package(Qt5Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

INCLUDE_DIRECTORIES(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/quex

) 

SET( SOURCES
    Token.cpp
    Tokenizer.cpp
    quex/sqllexer.cpp
    SqlSyntaxhighLighter.cpp
)

ADD_LIBRARY( tokenizer STATIC ${SOURCES} )
TARGET_LINK_LIBRARIES( tokenizer )
qt5_use_modules(tokenizer Widgets)
