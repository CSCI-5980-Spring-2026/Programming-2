cmake_minimum_required(VERSION 3.28)
project(GopherEngine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Core library
add_library(GopherEngineCore)
target_compile_features(GopherEngineCore PUBLIC cxx_std_17)
target_include_directories(GopherEngineCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE GOPHERENGINECORE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GopherEngine/Core/*.cpp
)
target_sources(GopherEngineCore PRIVATE ${GOPHERENGINECORE_SOURCES})
target_link_libraries(GopherEngineCore PUBLIC SFML::Window)

# Platform independence library
add_library(GopherEnginePlatform)
target_compile_features(GopherEnginePlatform PUBLIC cxx_std_17)
target_include_directories(GopherEnginePlatform PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE GOPHERENGINEPLATFORM_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GopherEngine/Platform/*.cpp
)
target_sources(GopherEnginePlatform PRIVATE ${GOPHERENGINEPLATFORM_SOURCES})
target_link_libraries(GopherEnginePlatform PUBLIC SFML::Window)

# Renderer library
add_library(GopherEngineRenderer)
target_compile_features(GopherEngineRenderer PUBLIC cxx_std_17)
target_include_directories(GopherEngineRenderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE GOPHERENGINERENDERER_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GopherEngine/Renderer/*.cpp
)
target_sources(GopherEngineRenderer PRIVATE ${GOPHERENGINERENDERER_SOURCES})
target_link_libraries(GopherEngineRenderer PUBLIC SFML::Window)

# Test executable
add_executable(MainLoopTest)
target_compile_features(MainLoopTest PRIVATE cxx_std_17)
target_include_directories(MainLoopTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE TESTAPP_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MainLoopTest/*.cpp
)
target_sources(MainLoopTest PRIVATE ${TESTAPP_SOURCES})
target_link_libraries(MainLoopTest PRIVATE GopherEngineCore)
target_link_libraries(MainLoopTest PRIVATE GopherEnginePlatform)
target_link_libraries(MainLoopTest PRIVATE GopherEngineRenderer)

# Set startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MainLoopTest)