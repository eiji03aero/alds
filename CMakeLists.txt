cmake_minimum_required(VERSION 3.13.4)
enable_testing()
set(CMAKE_CXX_STANDARD 14)

set(MAIN_NAME alds)
project(${MAIN_NAME})

file(GLOB_RECURSE SOURCES src/*.cpp)

include_directories(include test)
add_executable(${MAIN_NAME} ${SOURCES})

# -------------------- gtest --------------------
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

function(alds_test test_file)
  get_filename_component(test_target_name ${test_file} NAME_WE)

  add_executable(${test_target_name} "")
  target_sources(${test_target_name}
    PRIVATE
      "test/alds/util.h"
      ${test_file}
      )
  target_link_libraries(${test_target_name} gtest_main)
  add_test(NAME ${test_target_name} COMMAND ${test_target_name})
endfunction(alds_test)

alds_test("test/alds/sort/1_1_d_maximum_profit.cpp")
alds_test("test/alds/sort/1_1_a_insertion_sort.cpp")
alds_test("test/alds/sort/1_2_a_bubble_sort.cpp")
alds_test("test/alds/sort/1_2_b_selection_sort.cpp")
alds_test("test/alds/sort/1_2_c_stable_sort.cpp")
alds_test("test/alds/sort/1_2_d_shell_sort.cpp")
alds_test("test/alds/data/1_3_a_stack.cpp")
alds_test("test/alds/data/1_3_b_queue.cpp")
alds_test("test/alds/data/1_3_c_doubly_linked_list.cpp")
alds_test("test/alds/data/1_3_d_areas_on_the_cross_section_diagram.cpp")
alds_test("test/alds/search/1_4_a_linear_search.cpp")
alds_test("test/alds/search/1_4_b_binary_search.cpp")
