cmake_minimum_required(VERSION 3.10)
project(cpp_python_integration)

set(CMAKE_BUILD_TYPE Release)

option(WITH_CPPYY "cppyy bidings" OFF)
option(WITH_PYBIND "pybind" OFF)

find_package(Eigen3)

set(SOURCES robot.cpp)
set(HEADERS robot.h)

set(MY_LIBS robot_lib)

add_library(${MY_LIBS} SHARED ${SOURCES})

if(WITH_PYBIND)
    set(MY_LIBS ${MY_LIBS} robotpb_lib)
    add_subdirectory(pybind11)
    pybind11_add_module(robotpb_lib ${SOURCES} robot_pybind.cpp)
endif()

foreach(MY_LIB ${MY_LIBS})
    set_target_properties(${MY_LIB} PROPERTIES POSITION_INDEPENDENT_CODE ON)
    target_include_directories(${MY_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_include_directories(${MY_LIB} PRIVATE ${Eigen3_INCLUDE_DIRS})
endforeach()

add_executable(main main.cpp)
target_link_libraries(main robot_lib)

if(WITH_CPPYY)
execute_process(COMMAND cling-config --cmake OUTPUT_VARIABLE CPPYY_MODULE_PATH OUTPUT_STRIP_TRAILING_WHITESPACE)
message("CPPYY_MODULE_PATH: " ${CPPYY_MODULE_PATH})
list(INSERT CMAKE_MODULE_PATH 0 ${CPPYY_MODULE_PATH})

find_package(Cppyy)

cppyy_add_bindings(
   "robot_lib" "0.0.1" "Olivier" "ok@ok.com"
   LANGUAGE_STANDARD "14"
   GENERATE_OPTIONS "-D__PIC__;-Wno-macro-redefined"
   INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
   LINK_LIBRARIES robot_lib
   H_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
   H_FILES ${HEADERS})
endif()
