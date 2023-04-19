set(BINARY ${CMAKE_PROJECT_NAME}_tst)

add_executable(${BINARY} AllTests.cpp)

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest gmock)