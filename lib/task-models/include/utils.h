#include <iostream>
#include <Eigen/Dense>

/**
 * sums a matrix and checks if approximately equal to 1.0
 * @param  array an eigen matrix
 * @param  name  name of the array
 * @return       true/false if success/failure
 */
bool assertNormal(Eigen::MatrixXd array, std::string name="array");
