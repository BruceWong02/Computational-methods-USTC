
#include "../include/LinearFuncsSolver.h"
extern double epsilon;
double y[100];
double zero[100];

void GaussEliminationWithPartialPivoting(double A[100][100])
{
    double b[100];
    GenerateVector(b, 0.5*0.01*0.01);
    // make corrections
    b[99] = b[99] - (epsilon + 0.01);

    // 上三角化
    for (int i=0; i<99; i++)
    {
        // Select column pivot
        if (abs(A[i][i]) < abs(A[i+1][i]))
        {
            for (int j=i; j<100; j++)
            {
                Permuting(A[i][j], A[i+1][j]);
                Permuting(b[i], b[i+1]);
            }
        }
        // Elimination.
        A[i+1][i] = A[i+1][i]/A[i][i];
        for (int j=i+1; j<100; j++)
        {
            A[i+1][j] = A[i+1][j] - A[i+1][i]*A[i][j];
        }
        b[i+1] = b[i+1] - A[i+1][i]*b[i];
    }

    // derive solution
    b[99] = b[99]/A[99][99];
    for (int i=98;i>-1;i--)
    {
        for (int j=i+1;j<100;j++)
        {
            b[i] = b[i] - b[j]*A[i][j];
        }
        b[i] = b[i] / A[i][i];
    }

    // Output results.
    printf("/**********************************************/\n");
    printf("Solution by Gauss Elimination with partial pivoting:\nx = [");
    for (int i=0; i<100; i++)
    {
        printf("%f, ", b[i]);
        if (9 == i%10)
        {
            printf("\n\t");
        }
    }
    printf("]\n/**********************************************/\n");

    // Compare with accurate solution
    GenerateVector(zero, 0.);
    printf("The error related to accurate solution is: %f%%\n\n", 100.*Distance(b, y)/Distance(y, zero));

}


void Gauss_SeidelIteration(double R[100][100])
{
    double delta = 0.000001;
    double x1[100] = {0};
    double x0[100] = {10};

    // Iteration
    while (Distance(x1, x0) > delta)
    {   
        // copy x1 to x0
        for (int i=0;i<100;i++)
        {
            x0[i] = x1[i];
        }
        // update x1
        for (int i=0;i<100;i++)
        {
            x1[i] = -0.5*0.01*0.01/(2*epsilon+0.01);
            // make corrections
            if (99 == i)
            {
                x1[i] = -(0.5*0.01*0.01 - epsilon - 0.01)/(2*epsilon+0.01);
            }        
            for (int j=0;j<100;j++)
            {
                x1[i] = x1[i] + R[i][j]*x1[j];
            }
        }
    }
    
    // Output results.
    printf("/**********************************************/\n");
    printf("Solution by Gauss Seidel iteration:\nx = [");
    for (int i=0; i<100; i++)
    {
        printf("%.4f, ", x1[i]);
        if (9 == i%10)
        {
            printf("\n\t");
        }
    }
    printf("]\n/**********************************************/\n");

    // Compare with accurate solution
    GenerateVector(zero, 0.);
    printf("The error related to accurate solution is: %f%%\n\n", 100.*Distance(x1, y)/Distance(y, zero));

}


void GenerateMatrix(double Down, double Mid, double Up, double A[100][100])
{
    A[0][0] = Mid;
    A[99][99] = Mid;
    A[0][1] = Up;
    A[99][98] = Down;

    for (int i=1; i<99; i++)
    {
        A[i][i-1] = Down;
        A[i][i] = Mid;
        A[i][i+1] = Up;
    }
}


void Permuting(double a, double b)
{
    double term;

    term = a;
    a = b;
    b = term;
}


void GenerateVector(double b[100], double value)
{
    for (int i=0;i<100;i++)
    {
        b[i] = value;
    }
}


double Distance(double X1[100], double X0[100])
{
    double distance = 0;

    for (int i=0;i<100;i++)
    {
        distance = distance + (X1[i] - X0[i])*(X1[i] - X0[i]);
    }
    distance = sqrt(distance);

    return distance;
}


void CalAccuSol(double epsilon)
{
    for (int i=0;i<100;i++)
    {
        y[i] = 0.5 * (1 - exp(-0.01*i/epsilon)) /(1 - exp(-1/epsilon)) + 0.5*0.01*i;
    }
}

