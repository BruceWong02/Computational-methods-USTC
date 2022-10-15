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


void MatrixInit_Rand_0_1(int n, int m, double **M)
{
    // set random number seed
    srand((unsigned) time(NULL));

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            M[i][j] = rand() / RAND_MAX;
        }
    }
}


void MatrixInit_0(int n, int m, double **M)
{
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            M[i][j] = 0.;
        }
    }
}


void VectInit_Same(int n, double *Vector, double value)
{
    for (int i=0;i<n;i++){
        Vector[i] = value;
    }
}


double Distance(int n, double *X1, double *X0)
{
    double distance = 0.;

    for (int i=0;i<n;i++){
        distance = distance + (X1[i] - X0[i])*(X1[i] - X0[i]);
    }
    distance = sqrt(distance);

    return distance;
}


void MatrixMutiply(int n, int m, double **Matrix1, double **Matirx2, double **Matrix3)
{
    // buffer
    double Matrix12[n][n];
    MatrixInit_Same(n, n, Matrix12, 0);

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            for (int k=0;k<m;k++){
                Matrix12[i][j] = Matrix12[i][j] + Matrix1[i][k]*Matirx2[k][j];
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            Matrix3[i][j] = Matrix12[i][j];
        }
    }    
}


void Gauss_Seidel_iter(int n, double **A, double *X, double *b, double delta)
{
    double delta = 0.000001;
    double x1[n];
    double x0[n];
    VectInit_Same(n, x1, 0);
    VectInit_Same(n, x0, 10);

    // Calculate M
    double M[n][n];
    for (int i=0;i<n;i++){   
        for (int j=0;j<n;j++){
            M[i][j] = (i==j ? 0 : (- A[i][j] / A[i][i]));
        }
    }
    // Calculate b=D^{-1}b
    for (int i=0;i<n;i++){
        b[i] = b[i] / A[i][i];
    } 

    // Iteration
    while (Distance(n, x1, x0) > delta){   
        // copy x1 to x0
        for (int i=0;i<n;i++){
            x0[i] = x1[i];
        }
        // update x1
        for (int i=0;i<n;i++){
            x1[i] = b[i];       
            for (int j=0;j<n;j++){
                x1[i] = x1[i] + M[i][j]*x1[j];
            }
        }
    }

    // return X
    for (int i=0;i<n;i++){
        X[i] = x1[i];
    }
}


void Eigvalue_Jacobi(int n, double **Matrix, double *Eigvalues)
{

}


void Eigvector(int n, double **Matrix, double *Eigvector,
                void(*solver)(int, double**, double*, double*))
{

}


void SVD()
{

}



