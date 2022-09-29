
#include "../include/LinearFuncsSolver.h"

double** MatrixGenerator(int n, int m)
{
    double **Matrix;

    // detect input error
    if (n<=0 || m<=0)
    {
        printf("Matrix parameters input error!!!");
        return NULL;
    }

    // generate Matrix with malloc
    Matrix = (double **)malloc(sizeof(double *)*n);
    for (int i=0;i<m;i++)
    {
        Matrix[i] = (double *)malloc(sizeof(double)*m);
    }

    return Matrix;
}


void FreeMatrixMemory(double **Matrix, int m)
{
    for (int i=0;i<m;i++)
    {
        free(Matrix[i]);
    }
    free(Matrix);
}


void FillA1(double **A1)
{
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            A1[i][j] = 1./(9-i-j);
        }
    }
}


void FillA2(double **A2)
{
    FILE * fp = fopen("A2.txt", "r");
    if (NULL == fp)
    {
        printf("Failed to open A2.txt!!!");
        exit(-1);
    }

    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            fscanf(fp, "%d", &A2[i][j]);
        }
    }

    fclose(fp);  
}


void DoolittleFactor(double **A, double **L, double **U)
{
    int i;
}

void GetUX_Doo(int n, double **L, double *b, double *Y)
{

}

void GetX_Doo(int n, double **U, double *Y, double *X)
{
    
}


void MinEig_IPM(double **A, int n, double epsilon)
{
    double X[n];
    double Y[n];
    double lambda1 = 1.;
    double lambda2 = 1.;
    for (int i=0;i<n;i++)
    {
        X[i] = 1.;
    }

    double **L, **U;
    DoolittleFactor(A, L, U);

    do
    {
        // update
        for (int i=0;i<n;i++)
        {
            Y[i] = X[i]/lambda2;
        }
        lambda1 = lambda2;

        GetX_Doo(n, U, Y, X);

        // get lambda2
        lambda2 = X[0];
        for (int i=1;i<n;i++)
        {
            if (abs(X[i]) > abs(lambda2))
            {
                lambda2 = X[i];
            }
        }

    } while (abs(lambda2 - lambda1) > epsilon);
    
    
    


    // printf("sizeof X[n] : %d", sizeof(X));

}
