PROJECT ( QtPong )
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8.11 )

# for g++ and clang++
IF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" )
    IF ( CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.7.0" )
        ADD_DEFINITIONS ( -std=c++0x )
    ELSE ()
        ADD_DEFINITIONS ( -std=c++11 )
    ENDIF ()
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" )
    # will have to adjust this... older clang versions may need -std=c++0x
    # but I could not find an exact version number :-/
    ADD_DEFINITIONS ( -std=c++11 )
ENDIF ()

SET ( CMAKE_INCLUDE_CURRENT_DIR ON )
SET ( CMAKE_AUTOMOC ON )

FILE ( GLOB pong_SOURCES src/*.cxx )
FILE ( GLOB pong_HEADERS src/*.hxx )

FIND_PACKAGE ( Qt5Core REQUIRED )
FIND_PACKAGE ( Qt5Gui REQUIRED )
FIND_PACKAGE ( Qt5Widgets REQUIRED )
FIND_PACKAGE ( Qt5Script REQUIRED )

ADD_EXECUTABLE ( QtPong WIN32 ${pong_SOURCES} ${pong_HEADERS} )
TARGET_LINK_LIBRARIES ( QtPong Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Script )

INSTALL ( TARGETS QtPong DESTINATION bin )

