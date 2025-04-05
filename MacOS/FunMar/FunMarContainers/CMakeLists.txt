project(FunMarContainers)

set(SOURCE_LIB Abstraction.cpp 
	FunctionAbstraction.cpp
	Rule.cpp)

add_library(FunMarContainers STATIC ${SOURCE_LIB})

target_include_directories(FunMarContainers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
