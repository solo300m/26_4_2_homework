cmake_minimum_required (VERSION 3.8)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable (Task_2 "Task_2.cpp" "${MY_INCLUDE_DIR}/Task_2.h" "${MY_INCLUDE_DIR}/PhonNumber.h" "${MY_INCLUDE_DIR}/Client.h" "${MY_INCLUDE_DIR}/BookPhon.h")

target_include_directories(Task_2 PUBLIC ${MY_INCLUDE_DIR})