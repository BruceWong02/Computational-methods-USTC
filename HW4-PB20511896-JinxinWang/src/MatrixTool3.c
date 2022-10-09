#include "../include/MatrixTool3.h"


double** MatrixGenerator(int n, int m, void(*init)(int, int, double**))
{
    // detect input error
    if (n<=0 || m<=0){
        printf("Matrix parameters input error!!!");
        exit(EXIT_FAILURE);
    }

    // generate Matrix with malloc
    double **Matrix = (double **)malloc(sizeof(double *)*n);
    for (int i=0;i<m;i++){
        Matrix[i] = (double *)malloc(sizeof(double)*m);
    }

    Init(n, m, Matrix);

    return Matrix;
}


void FreeMatrixMemory(double **Matrix, int m)
{
    for (int i=0;i<m;i++){
        free(Matrix[i]);
    }
    free(Matrix);
}


void InitRand_0_1(int n, int m, double **M)
{
    // set random number seed
    srand((unsigned) time(NULL));

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            M[i][j] = rand() / RAND_MAX;
        }
    }
}


// Gauss-Seidel
    // double delta = 0.000001;
    // double x1[100] = {0};
    // double x0[100] = {10};

    // // Iteration
    // while (Distance(x1, x0) > delta)
    // {   
    //     // copy x1 to x0
    //     for (int i=0;i<100;i++)
    //     {
    //         x0[i] = x1[i];
    //     }
    //     // update x1
    //     for (int i=0;i<100;i++)
    //     {
    //         x1[i] = -0.5*0.01*0.01/(2*epsilon+0.01);
    //         // make corrections
    //         if (99 == i)
    //         {
    //             x1[i] = -(0.5*0.01*0.01 - epsilon - 0.01)/(2*epsilon+0.01);
    //         }        
    //         for (int j=0;j<100;j++)
    //         {
    //             x1[i] = x1[i] + R[i][j]*x1[j];
    //         }
    //     }
    // }


