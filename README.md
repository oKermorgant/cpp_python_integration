# Comparison between C++ / Python / pybind11 / cppyy

This project is used to show Python C++ extension through cppyy and pybind11.

## Dependencies

 - `Eigen3` (mandatory)
 - `cppyy` (optionnal): `pip3 install cppyy`
 - `pybind11` (optionnal): `git clone https://github.com/pybind/pybind11` and install or copy to this folder

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
 
## Typical output in ipython3

The bindings being dynamically generated, the first call will take more time. After that the call from C++ from Python, whether with `pybind11` or `cppyy`, will be much more efficient:
 
```
%run compare.py

# solve 100 times a problem of dim. 500 (M.x = v)

elapsed_time(100, 500)   # would be smarter to run elapsed_time(0,0) to instantiate the bindings
   C++     -> 57.43 ms
   Python  -> 1750.95 ms
   cppyy   -> 2399.86 ms
   pybind  -> 2414.47 ms

elapsed_time(100, 500)
   C++     -> 63.29 ms
   Python  -> 1761.10 ms
   cppyy   -> 477.76 ms
   pybind  -> 476.82 ms
```

