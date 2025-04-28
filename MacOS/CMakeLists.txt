cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME FunMarProg)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()


if (NOT antlr4-runtime_FOUND)
    if(APPLE)
        # Для macOS
        include_directories(antlr4-runtime)
	link_directories(/opt/homebrew/lib)
    elseif(UNIX)
        # Для Linux
        include_directories(/usr/local/include /usr/include)
        link_directories(/usr/local/lib /usr/lib)
    endif()
endif()

include_directories(
    FunMar/FunMarCore
    FunMar/FunMarAntlrTree
    FunMar/FunMarContainers
)

add_definitions(-DFILE_PATH="${CMAKE_SOURCE_DIR}/input/main.fm")

set(SOURCE_FILES
    samples/main.cpp
)

add_executable(main ${SOURCE_FILES})

add_subdirectory(FunMar/FunMarCore)
add_subdirectory(FunMar/FunMarAntlrTree)
add_subdirectory(FunMar/FunMarContainers)

target_link_libraries(main antlr4-runtime)
target_link_libraries(main FunMarCore)

set(LIBRARY FunMarCore antlr4-runtime)

include_directories(gtest)
set(TESTS "test_${PROJECT_NAME}")
add_subdirectory(gtest)
add_subdirectory(test)

set_target_properties(main PROPERTIES
	XCODE_GENERATE_SCHEME TRUE
	XCODE_SCHEME_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/FunMar"
)

message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "   System: ${CMAKE_SYSTEM_NAME}")
message( STATUS "")
