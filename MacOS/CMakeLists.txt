cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME FunMarProg)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(antlr4-runtime)
link_directories(/opt/homebrew/lib)

find_package(antlr4-runtime REQUIRED)


include_directories(FunMar/FunMarCore)
include_directories(FunMar/FunMarAntlrTree)
include_directories(FunMar/FunMarContainers)

add_definitions(-DFILE_PATH="${CMAKE_SOURCE_DIR}/input/FunMarMalloc.fm")

set(SOURCE_FILES
    samples/main.cpp
)

add_executable(main ${SOURCE_FILES})

add_subdirectory(FunMar/FunMarCore)
add_subdirectory(FunMar/FunMarAntlrTree)
add_subdirectory(FunMar/FunMarContainers)

target_link_libraries(main antlr4-runtime)
target_link_libraries(main FunMarCore)


message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")
