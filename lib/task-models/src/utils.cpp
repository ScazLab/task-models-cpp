#include <utils.h>

using namespace std;
using Eigen::MatrixXd;

bool isNormal(MatrixXd _array, double _epsilon, string _name)
{
    // e.g:
    // [1.0, 0] => 1.0
    // [0.5, 0.3 => 1.0
    //  0.1, 0.1]
    double sum = _array.sum();

    // e.g:
    // 1.0 == 1.
    if(sum > 1.0 + _epsilon || sum < 1.0 - _epsilon)
    {
        cout << "[Error] Probabilities in " << _name << " should sum to 1." << endl;
        return false;
    }

    return true;
}
