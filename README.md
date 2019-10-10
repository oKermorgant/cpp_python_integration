# Simple comparison between C++ / Python / pybind11 / cppyy

Clone this repo with `--recurse-submodules` to have access to pybind11.

## Dependencies

Eigen3 (mandatory), cppyy and pybind11 (optionnal)

## Compiling

Create a `build` directory (name is mandatory) and call cmake with options -DWITH_PYBIND and -DWITH_CPPYY depending on the tools you want to compare.

## Comparing

Execute `compare.py` from `ipython3` and call `elapsed_time(n, dim)` with various dimensions.

## C++ side

A `Robot` class is defined with a `::bigComputation` method that solves some linear algebra problem. The problem is of dimension `dim` and is solved `n` times.

## Python side

The elapsed_time function compares the solving time of the same problem with calls to:
 - Pure C++ (executable from command line)
 - Pure Python (with numpy)
 - pybind11
 - cppyy
 
 

