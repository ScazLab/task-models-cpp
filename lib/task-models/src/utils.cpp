#include <utils.h>
#include <typeinfo>

using namespace std;
using Eigen::MatrixXd;

bool assertNormal(MatrixXd array, string name)
{
	// e.g:
	// [1.0, 0] => [1.0]
	// [0.5, 0.3 => [1.0]
	//  0.1, 0.1]
	MatrixXd sumMatrix(1,1);
	sumMatrix(0,0) = array.sum();

	// e.g:
	// [1.0] == [1.]
	if(not sumMatrix.isApprox(MatrixXd::Constant(1,1,1.)))
	{
		cout << "[Error] Probabilities in " << name << " should sum to 1." << endl;
		return false;
	}

	return true;
}
