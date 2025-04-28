project(FunMarCore)

set(SOURCE_LIB FunMarCompiler.cpp
		Kernel.cpp
		EnvironmentManager.cpp
		Environment.cpp
		AbstractionManager.cpp
		DecisionManager.cpp)

add_library(FunMarCore STATIC ${SOURCE_LIB})

target_include_directories(FunMarCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(FunMarCore PUBLIC 
	FunMarAntlrTree 
	FunMarContainers
	${ANTLR4_CPP_RUNTIME})
