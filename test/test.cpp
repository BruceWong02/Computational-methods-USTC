#include "test.h"
#include <math.h>
using namespace std;
int main()
{
    double a = pow(0.1, 17);
    double b = 0.49*pow(0.1, 17);
    cout << "a:" << a << "\tb:" << b << "\ta+b:" << (a+b)*pow(10, 17);
    // for (int i=0;i<3;i++){
    //     cout << i%10 << "\t";
    //     // cout << endl;
    // }

    return 0;
}