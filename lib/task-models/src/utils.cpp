#include <utils.h>

using namespace std;
using Eigen::MatrixXd;

bool isNormal(MatrixXd array, double epsilon, string name)
{
	// e.g:
	// [1.0, 0] => 1.0
	// [0.5, 0.3 => 1.0
	//  0.1, 0.1]
	double sum = array.sum();

	// e.g:
	// 1.0 == 1.
	if(sum > 1.0 + epsilon || sum < 1.0 - epsilon)
	{
		cout << "[Error] Probabilities in " << name << " should sum to 1." << endl;
		return false;
	}

	return true;
}
