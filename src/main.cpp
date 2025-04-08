// serial version.
// main; calls the Solver class and its children solvers.
// the system of equations takes the form Ax = b, where A is a 3 x 3 matrix and x & b are both 1 x 3 column vectors.
// we seek to find the 3 elements of x and see which algorithm/method converges the fastest.

#include <iostream>
#include "laSolver.hpp"

int main() {

	// matrix A
	Eigen::MatrixXd A {

		{8, -1, 0},
		{-1, 8, -1},
		{0, -1, 8},

	};

	// column vector b
	Eigen::VectorXd b {{20, 16, 16}};

	// number of iterations to perform
	int maxIterations {2000};

	// accepted level of error allowed
	double tolerance {1e-6};

	// relaxation factor for SOR algorithm
	double relaxFactor {1.25};

	// let user know which method is being used and call these methods

	// Jacobi method
	std::cout<<"Jacobi Method:\n";

	// create a Jacobi object
	Jacobi jacobi(A, b, maxIterations, tolerance);

	// call the solver and transpose the object
	std::cout<<jacobi.solve().transpose()<<"\n\n";

	// Gauss-Seidel Method
	std::cout<<"Gauss-Seidel Method:\n";

	// create a gauss-seidel object
	GaussSeidel gs(A, b, maxIterations, tolerance);

	// call the solver and transpose the object
	std::cout<<gs.solve().transpose()<<"\n\n";

	// SOR method
	std::cout<<"SOR Method:\n";

	// create a SOR object
	SOR sor(A, b, maxIterations, tolerance, relaxFactor);

	// call the solver and transpose the object
	std::cout<<sor.solve().transpose()<<"\n\n";

	// end of program
}
