set(BINARY ${CMAKE_PROJECT_NAME})

#add_subdirectory(IModule)
add_subdirectory(PatternsMatcherModules)

add_executable(${BINARY} main.cpp)

target_sources(${BINARY} PRIVATE $<TARGET_OBJECTS:PatternsMatcherModules>)
target_link_libraries(${BINARY} pthread)

add_library(${BINARY}_lib STATIC 
    $<TARGET_OBJECTS:PatternsMatcherModules> 
)