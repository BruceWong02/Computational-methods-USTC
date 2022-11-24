#include "../include/NumInte.h"


double Romberg(double(*f)(double), double a, double b, int n, int M, double e)
{
    double h = b-a;
    double hk = 0.0;

    // times of iteration
    const int m = M;
    int final_k = 0;

    double R[m][m];
    R[0][0] = (f(a)+f(b))*h/2.;

    for (int k=1;k<m;k++)
    {
        final_k = k;

        hk = h/pow(2, k);
        double iMax = pow(2, k-1);

        R[k][0] = 0.;
        for (int i=0;i<iMax;i++)
        {
            R[k][0] = R[k][0] + f(a+(2*i+1)*hk);
        }
        R[k][0] = R[k-1][0]/2 + hk*R[k][0];

        for (int j=1;j<k+1;j++)
        {
            R[k][j] = R[k][j-1] + (R[k][j-1]-R[k-1][j-1])/(pow(4, j)-1);
        }

        if (fabs(R[k][k]-R[k-1][k-1]) < e)
        {
            return R[final_k][final_k];
        }
    }

    return R[final_k][final_k];

}

