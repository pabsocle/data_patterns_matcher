set(BINARY ${CMAKE_PROJECT_NAME})

#add_subdirectory(IModule)
add_subdirectory(PatternsMatcherModules)

add_executable(${BINARY} main.cpp)

add_library(${BINARY}_lib STATIC 
    $<TARGET_OBJECTS:PatternsMatcherModules> 
)