
cmake_minimum_required (VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

project (median_project)

#FILE(GLOB src_files ${CMAKE_SOURCE_DIR}/src/*.cpp)
#add_executable(median ${src_files})

#FILE(GLOB test_files ${CMAKE_SOURCE_DIR}/test/*.cpp)
#add_executable(median_test ${test_files})

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(test/googletest)
