cmake_minimum_required(VERSION 3.5)
list(APPEND CMAKE_PREFIX_PATH $ENV{QT_DIR})

project(comPortScanner VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add custom app icon
set(APPICON_WIN "${CMAKE_CURRENT_SOURCE_DIR}/assets/app/appIcon.rc")

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Svg SerialPort)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Svg SerialPort)

set(VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/include/version.h")
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include")

# Glob source files.
file(GLOB_RECURSE PROJECT_SOURCES LIST_DIRECTORIES false "src/*.cpp" "src/*.h" "assets/*.qrc" "src/*.ui")

qt_add_executable(comPortScanner
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    "${VERSION_FILE}"
    ${APPICON_WIN} # add custom app icon
)

add_custom_target(VersionFile ALL
    COMMAND ${CMAKE_COMMAND}
    -D "PROJECT_VERSION=${PROJECT_VERSION}"
    -D "VERSION_FILE=${VERSION_FILE}"
    -P "${CMAKE_CURRENT_LIST_DIR}/tools/cmake/version.cmake"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Creating ${VERSION_FILE}"
)
include(tools/cmake/version.cmake)

target_link_libraries(comPortScanner PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Svg
    Qt${QT_VERSION_MAJOR}::SerialPort
)

set_target_properties(comPortScanner PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER ni-m.ch
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE # comment to enable cli output
)

qt_finalize_executable(comPortScanner)
include(tools/cmake/windeployqt.cmake)

if(WIN32)
    windeployqt(comPortScanner)
endif()

# # Copy files into build directory
add_custom_command(
    TARGET comPortScanner POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/LICENSE.md
    ${CMAKE_CURRENT_BINARY_DIR}/LICENSE.md
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md)
