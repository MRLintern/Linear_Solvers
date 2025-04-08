#pragma once

// solver class for Jacobi, Gauss-Seidel and Successive Over Relaxation (SOR) algorithms
// the system of equations solved takes the form Ax = b
// A: matrix, x: column vector, whose elements we wish to find and b, a column vector whose values we know

#include <iostream>
#include <memory>
#include <chrono>
#include <Eigen/Dense>

class Solver {

protected:

	Eigen::MatrixXd m_A; // matrix; values known
	Eigen::VectorXd m_b; // column vector; values known
	int m_maxIterations; // total number of iterations to perform
	double m_tolerance; // level of error thats acceptable

public:

	// constructor; initialise data members for Solver class
	Solver(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, int maxIterations, double tolerance)

		: m_A(A), m_b(b), m_maxIterations(maxIterations), m_tolerance(tolerance) {}

	// to be implemented by derived classes
	// all sub-classes must define a solve() function
	virtual Eigen::VectorXd solve() = 0;
};

// derived class implementing the Jacobi algorithm
class Jacobi : public Solver {

public:

	// inherit constructors from Solver class
	using Solver::Solver;

	// override solve() with Jacobi implementation
	Eigen::VectorXd solve() override;

};

// Gauss-Seidel method solver; dervied class from Solver
class GaussSeidel : public Solver {

public:

	// inherit constructors from Solver class
	using Solver::Solver;

	// override solve() with Gauss-Seidel implementation
	Eigen::VectorXd solve() override;

};

// derived class implementing SOR algorithm
class SOR : public Solver {

private:

	// relaxation factor: values chosen experimentally between 1.1 - 1.9
	double m_relaxFactor;

public:

	// constructor; initialise data members for Solver & SOR class and relaxation factor
	SOR(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, int maxIterations, double tolerance, double relaxFactor);

	// override solve() with SOR implementation
	Eigen::VectorXd solve() override;

};
