#include <iostream>
#include <Eigen/Dense>

/**
 * sums a matrix and checks if approximately equal to 1.0
 * @param  array   an eigen matrix
 * @param  name    name of array
 * @param  epsilon optional interval for check
 * @return         true/false if success/failure
 */
bool isNormal(Eigen::MatrixXd array, double epsilon=1e-10, std::string name="array");
