# Comparison between C++ / Python / pybind11 / cppyy

## Dependencies

 - Eigen3 (mandatory)
 - cppyy (optionnal): `pip3 install cppyy`
 - pybind11 (optionnal): `git clone https://github.com/pybind/pybind11` and install or copy to this folder

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
 
 

