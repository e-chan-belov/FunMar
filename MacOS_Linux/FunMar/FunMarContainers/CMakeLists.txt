project(FunMarContainers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_LIB Abstraction.cpp 
	FunctionAbstraction.cpp
	Rule.cpp
	FunMarStack.cpp
)

add_library(FunMarContainers STATIC ${SOURCE_LIB})

target_include_directories(FunMarContainers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
