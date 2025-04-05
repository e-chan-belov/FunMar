project(FunMarAntlrTree)

include_directories(/opt/homebrew/Cellar/antlr4-cpp-runtime/4.13.2/include/antlr4-runtime)
link_directories(/opt/homebrew/lib)

find_package(antlr4-runtime REQUIRED)

set(SOURCE_LIB FunMarLexer.cpp 
	FunMarParser.cpp
	FunMarBaseVisitor.cpp)

add_library(FunMarAntlrTree STATIC ${SOURCE_LIB})

target_include_directories(FunMarAntlrTree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FunMarAntlrTree PUBLIC FunMarContainers)
