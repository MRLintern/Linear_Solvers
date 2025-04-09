// driver file for Solver class

#include "laSolver.hpp"

// Jacobi method
Eigen::VectorXd Jacobi::solve() {

	// number of rows for matrix A
	int n = m_A.rows();

	// set up x column vector with 0's
	Eigen::VectorXd x = Eigen::VectorXd::Zero(n); 

	// set up x column vector for new/updated values; holds updated values
	Eigen::VectorXd x_new = x;

	// for timing algorithm until convergence of algorithm
	auto start { std::chrono::high_resolution_clock::now() };

	for (int k{0}; k < m_maxIterations; ++k) {
		for (int i{0}; i < n; ++i) {

			double summation {0.0}; // this represents the greek letter found in the formula; sigma; summing LHS of Ax = b

			// compute A[i][j] * x[j] for j != i
			for (int j {0}; j < n; ++j) {

				if (j != i) {

					summation += m_A(i, j) * x(j); // sum (Ax)
				}
			}

			// update x[i]
			x_new(i) = (m_b(i) - summation) / m_A(i, i);
		}

		// check for convergence; note: Eucidean norm, p = 2
		if ((x_new - x).norm() < m_tolerance) {

			// stop timing for convergence
			auto end { std::chrono::high_resolution_clock::now() };

			// tell user how long it took for algorithm to converge
			std::cout<<"The Jacobi Method Converged in "<<k + 1<<" iterations.\n";

			// how long did it take for the algorithm to converge..?
			std::cout<<"The Jacobi Method Converged in "<<std::chrono::duration<double>(end - start).count()<<"s.\n";

			// new updated elements of x vector
			return x_new;

		}

		// update x with new values
		x = x_new;
	}

	// If max iterations reached, still measure time; end time
	auto end { std::chrono::high_resolution_clock::now() };

	// tell user about how long it took to reach max. iterations
	std::cout<<"The Jacobi Method Reached Max. Iterations in "<<std::chrono::duration<double>(end - start).count()<<"s.\n";

	return x;
}

// Gauss-Seidel Method
Eigen::VectorXd GaussSeidel::solve() {

	// number of rows of matrix A
	int n = m_A.rows();

	// set up x column vector with 0's
	Eigen::VectorXd x = Eigen::VectorXd::Zero(n);

	// previous values for x column vector
	Eigen::VectorXd x_previous = x;

	// start timing
	auto start { std::chrono::high_resolution_clock::now() };

	for (int k{0}; k < m_maxIterations; ++k) {

		x_previous = x;

		for (int i{0}; i < n; ++i) {

			double summation {0.0}; // greek letter in formula; sigma; summing LHS of Ax = b

			// use most recent updated values for j < i; j > i for previous values
			for (int j{0}; j < n; ++j) {

				if (j != i) {

					summation += m_A(i, j) * x(j); // sum (Ax); has x(j) been updated..?
				}
			}

			// update x(i)
			x(i) = (m_b(i) - summation) / m_A(i, i);
		}

		// check for convergence; note: Eucidean norm, p = 2
		if ((x - x_previous).norm() < m_tolerance) {

			// stop timing for convergence
			auto end { std::chrono::high_resolution_clock::now() };

			// how many iterations did it take for the algorithm to converge..?
			std::cout<<"The Gauss-Seidel Method Converged in "<<k + 1<<" iterations.\n";

			// time it took for the algorithm to converge
			std::cout<<"The Gauss-Seidel Method took "<<std::chrono::duration<double>(end - start).count()<<"s.\n";

			return x;
		}
	}

	// If max iterations reached, still measure time; end time
	auto end { std::chrono::high_resolution_clock::now() };

	// tell user about how long it took to reach max. iterations
	std::cout<<"The Gauss-Seidel Method Reached Max. Iterations in "<<std::chrono::duration<double>(end - start).count()<<"s.\n";

	return x;

}

// SOR Method
SOR::SOR(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, int maxIterations, double tolerance, double relaxFactor) 

	: Solver(A, b, maxIterations, tolerance), m_relaxFactor(relaxFactor) {}

Eigen::VectorXd SOR::solve() {

    // number of rows of matrix A
    int n = m_A.rows();

    // column x vector; elements to be found; initially 0
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);  

    // column x vector; previous values
    Eigen::VectorXd x_previous = x;

    // Start timing
    auto start {std::chrono::high_resolution_clock::now()};

    for (int k {0}; k < m_maxIterations; ++k) {

        x_previous = x;  // Store previous iteration values

        for (int i {0}; i < n; ++i) {

            double summation {0.0}; // this is the Greek symbol for summation, sigma

            // Compute summation for known values (Gauss-Seidel update)
            for (int j {0}; j < i; ++j) {

                summation += m_A(i, j) * x(j);  // Updated values; summation (Ax)
            }

            for (int j {i + 1}; j < n; ++j) {

                summation += m_A(i, j) * x_previous(j);  // previous values
            }

            // Compute new value with relaxation factor; this time x(i) uses the previous AND new values for x
            x(i) = (1 - m_relaxFactor) * x_previous(i) + (m_relaxFactor / m_A(i, i)) * (m_b(i) - summation);
        }

        // check for convergence; note: Eucidean norm, p = 2
        if ((x - x_previous).norm() < m_tolerance) {

        	// stop timing for convergence
			auto end { std::chrono::high_resolution_clock::now() };

			// how many iterations did it take for the algorithm to converge..?
			std::cout<<"The SOR Method Converged in "<<k + 1<<" iterations.\n";

			// time it took for the algorithm to converge
			std::cout<<"The SOR Method took "<<std::chrono::duration<double>(end - start).count()<<"s.\n";

			return x;
		}
    }

    // If max iterations reached, still measure time; end time
    auto end { std::chrono::high_resolution_clock::now() };

    // tell user about how long it took to reach max. iterations
	std::cout<<"The SOR Method Reached Max. Iterations in "<<std::chrono::duration<double>(end - start).count()<<"s.\n";

	return x;
}
