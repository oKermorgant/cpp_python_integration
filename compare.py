import sys
# insert at 1, 0 is the script path (or '' in REPL)
sys.path.insert(1, './build/')

try:
    from robot_lib import Robot as Robot_cppyy
    robot_cppyy = Robot_cppyy()
except:
    robot_cppyy = None
    
try:
    from robot_libpb import Robot as Robot_pybind
    robot_pybind = Robot_pybind()
except:
    robot_pybind = None
    
from numpy.linalg import solve, norm
from numpy.random import randn

from os import system
import time

def py_inv(n, dim):
    r = 0
    for _ in range(n):
        M = randn(dim, dim)
        v = randn(dim)
        r += norm(solve(M,v))
    return r

def cpp_inv(n, dim):
    system('./build/main {} {}'.format(n, dim))
    

candidates = [(cpp_inv, 'C++'), (py_inv, 'Python')]
if robot_cppyy != None:
    candidates.append((robot_cppyy.bigComputation, 'cppyy'))
if robot_pybind != None:
    candidates.append((robot_pybind.bigComputation, 'pybind'))


def elapsed_time(n, dim):
        
    for fct,method in candidates:
        t0 = time.time()
        fct(n, dim)
        print('{}\t-> {:.2f} ms'.format(method, 1000*(time.time() - t0)))
  
