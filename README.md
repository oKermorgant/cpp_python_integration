# Simple comparison between C++ / Python / pybind11 / cppyy

## Dependencies

Eigen3 (mandatory), cppyy and pybind11 (optionnal)

## Compiling

Create a build directory (name is mandatory) and call cmake with options -DWITH_PYBIND and -DWITH_CPPYY depending on the tools you want to compare

## C++ side

A Robot class is defined with a ::bigComputation method that solves some linear algebra problem.

## Python side

The elapsed_time function compares the solving time of the same problem with calls to:
 - Pure C++ (executable from command line)
 - Pure Python (with numpy)
 - pybind11
 - cppyy
 
 

