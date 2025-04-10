# Linear-Solvers

## Introduction
* Utilising __OOP__ with __C++__ and the __Eigen Library__, this software demonstrates the implementation of the __Jacobi__, __Gauss-Seidel__ and __Successive Over Relaxation (SOR)__ iterative methods for solving __Linear Algebraic Systems__, of the form, __Ax = b__.
* A __serial version__ has been developed. A __parallel version__ is currently being developed. A parallel version is developed so we can consider large systems of equations.
* In the parallel case, __Performance Metrics__, such as __Speed-Up__ and __Efficiency__ will be calculated.

## Iterative Solvers
* Below gives a brief overview of the algorithms.
### Jacobi Method
* TODO.
### Gauss-Seidel Method
* TODO.
### Successive Over Relaxation (SOR) Method
* TODO.
## Parallel Case
* TODO; the parallel case will make use of __OpenMP__.
## Requirements
* __Compiler__: `g++ 13.1.0`.
* __OS__: `Ubuntu 20.04`.
* `OpenMP`.
* `CMake`.
* `Eigen`.

## Getting and Using the Software
* `$ git clone git@github.com:MRLintern/Linear_Solvers.git`
* `$ cd Linear_Solvers`
* `$ mkdir build -p cd build`
* `$ cmake ..`
* `$ cmake --build .`
* `$ ./laSolver`

## Results
* TODO.
* A folder/directory will contain results and graphs of `Time-to-Convergence vs. Number of Iterations`. I see this as a requirement because I will vary the `Relaxation Factor` for the `SOR Algorithm`. At the moment, I have used `1.25` as the relaxation factor.
