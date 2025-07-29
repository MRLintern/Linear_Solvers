# Linear-Solvers
---

## Introduction
---
* Utilising __OOP__ with __C++__ and the __Eigen Library__, this software demonstrates the implementation of the __Jacobi__, __Gauss-Seidel__ and __Successive Over Relaxation (SOR)__ iterative methods for solving __Linear Algebraic Systems__, of the form, __Ax = b__.

## TODO: Software
---
* Develop a function which will save the __Convergence Rates__ to a `.csv` file for plotting/visualisation.
* Develop a `Python script` which will plot __Convergence Rates__.


## Iterative Solvers
---
* Below gives a brief overview of the algorithms.
### The Jacobi Method
* __Idea__: Updates each component of the solution vector independently using the values from the previous iteration.
* __Convergence__: Requires that the `coefficient matrix A` is `diagonally dominant` or `symmetric positive definite`.

  
### The Gauss-Seidel Method
* __Idea__: Like the `Jacobi Method`, but uses newly updated values as soon as they are available.
* __Convergence__: Often faster than the `Jacobi Method`. Also needs the `coefficient matrix A` to be `diagonally dominant` or `symmetric positive definite`.

### The Successive Over Relaxation (SOR) Method
* __Idea__: An extension of the `Gauss-Seidel Method` that uses a ___Relaxation Factor w___ to potentially `accelerate convergence`.
* __Parameter range__: __0 < w < 2__.
    * __w = 1__: `Gauss-Seidel Method`.
    * __w > 1__: `Over-relaxation` (usually speeds up convergence).

## Requirements
---
* __Compiler__: `g++ 13.1.0`.
* __OS__: `Ubuntu 20.04`.
* `CMake`.
* `Eigen`.

## Getting and Using the Software
---
* `$ git clone git@github.com:MRLintern/Linear_Solvers.git`
* `$ cd Linear_Solvers`
* `$ mkdir build -p cd build`
* `$ cmake ..`
* `$ cmake --build .`
* `$ ./laSolver`

## Results
---
* TODO.
---
  
