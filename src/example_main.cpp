#include <iostream>
#include <Eigen/Dense>

#include "example-lib/exampleClass.h"

int main()
{
    Eigen::MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << "Matrix is: " << std::endl << m << std::endl;

    exampleClass ec;
    printf("\nVal is: %i\n", ec.getVal());
}
