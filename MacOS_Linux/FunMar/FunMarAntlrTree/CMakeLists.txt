project(FunMarAntlrTree)

set(SOURCE_LIB FunMarLexer.cpp 
	FunMarParser.cpp
	FunMarBaseVisitor.cpp)

add_library(FunMarAntlrTree STATIC ${SOURCE_LIB})

target_include_directories(FunMarAntlrTree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FunMarAntlrTree PUBLIC 
	FunMarContainers
	${ANTLR4_CPP_RUNTIME})
