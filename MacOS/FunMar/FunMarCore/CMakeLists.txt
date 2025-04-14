project(FunMarCore)

include_directories(/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/include/antlr4-runtime)
link_directories(/opt/homebrew/lib)

find_package(antlr4-runtime REQUIRED)

set(SOURCE_LIB FunMarCompiler.cpp
		Kernel.cpp)

add_library(FunMarCore STATIC ${SOURCE_LIB})

target_include_directories(FunMarCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FunMarCore PUBLIC 
	FunMarAntlrTree 
	FunMarContainers)
