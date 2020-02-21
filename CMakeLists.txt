
cmake_minimum_required (VERSION 3.7) #hihger pls

set(CMAKE_CXX_STANDARD 14) #hihger pls
project (median_project)

FILE(GLOB src_files ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(median ${src_files})


# ################################## Test Related
# FILE(GLOB test_files ${CMAKE_SOURCE_DIR}/test/*.cpp)
# add_executable(median_test ${test_files})

# # Download and install GoogleTest
# include(ExternalProject)
# ExternalProject_Add(gtest
#   URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
#   PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
#   INSTALL_COMMAND "")
# ExternalProject_Get_Property(gtest source_dir binary_dir)

# # Configure the test to use GoogleTest
# add_dependencies(median_test gtest)
# include_directories(${source_dir}/include)
# target_link_libraries(median_test ${binary_dir}/libgtest.a)
# target_link_libraries(median_test ${binary_dir}/libgtest_main.a)

# enable_testing()
# ################################## ~Test Related





# include_directories(SYSTEM
#     ${GTEST_INCLUDE_DIRS})

# link_directories(
#     ${GTEST_LIBRARY_DIRS})

#     target_link_libraries(median_test
#         ${GTEST_LIBRARIES})



enable_testing()

FILE(GLOB test_files ${CMAKE_SOURCE_DIR}/test/*.cpp)
add_executable(median_test ${test_files})
add_subdirectory(test/googletest)
