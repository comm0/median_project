
set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

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