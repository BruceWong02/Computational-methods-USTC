
#include "../include/MatrixTool2.h"


double** MatrixGenerator(int n, int m)
{
    // detect input error
    if (n<=0 || m<=0)
    {
        printf("Matrix parameters input error!!!");
        exit(-1);
    }

    // generate Matrix with malloc
    double **Matrix = (double **)malloc(sizeof(double *)*n);
    for (int i=0;i<m;i++)
    {
        Matrix[i] = (double *)malloc(sizeof(double)*m);
    }

    Init2Zero(n, m, Matrix);

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


void Init2Zero(int n, int m, double **M)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            M[i][j] = 0;
        }
    }
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
        printf("fopen() failed!!!");
        exit(EXIT_FAILURE);
    }

    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            fscanf(fp, "%lf", &A2[i][j]);
        }
    }

    fclose(fp);  
}


void DoolittleDecom(int n, double **A, double **L, double **U)
{
    for (int i=0;i<n;i++)
    {
        // Calculate row i of U
        for (int j=i;j<n;j++)
        {
            U[i][j] = A[i][j];
            for (int j1=0;j1<i-1;j1++)
            {
                U[i][j] = U[i][j] - L[i][j1] * U[j1][i];
            }
        }
        // Calculate coloum i of L
        for (int k=i+1;k<n;k++)
        {
            L[k][i] = A[k][i];
            for (int k1=0;k1<i-1;k1++)
            {
                L[k][i] = L[k][i] - L[k][k1] * U[k1][k];
            }
            L[k][i] = L[k][i]/U[i][i];
        }
    }
}


void GetYofLY(int n, double **L, double *b, double *Y)
{
    for (int i=0;i<n;i++)
    {
        Y[i] = b[i];
        for (int j=0;j<i;j++)
        {
            Y[i] = Y[i] - Y[j]*L[i][j];
        }
        Y[i] = Y[i]/L[i][i];
    }
}


void GetXofUX(int n, double **U, double *Y, double *X)
{
    for (int i=n-1;i>-1;i--)
    {
        X[i] = Y[i];
        for (int k=n-1;k>i;k--)
        {
            X[i] = X[i] - X[k]*U[i][k];
        }
        X[i] = X[i]/U[i][i];
    }
}


void MinEig_IPM(char *filename, double **A, int n, double epsilon)
{
    // init
    // AX = Y <=> LUX = Y
    int N = n;
    double lambda1 = 1.; // last lambda
    double lambda2 = 1.; // new lambda
    double X[N];
    double Y[N];
    for (int i=0;i<n;i++)
    {
        X[i] = 1.;
    }
    double UX[n];
    int k = 0;


    // Create output file.
    FILE * fp = fopen(filename, "w+");
    if (NULL == fp)
    {
        printf("fopen() failed!!!");
        exit(EXIT_FAILURE);
    }
    // init output file
    // title
    fprintf(fp, "k,Lambda,X(k),");
    for (int i=1;i<n;i++)
    {
        fprintf(fp, ",");
    }
    fprintf(fp, "Y(k)\n%d,,", k);
    // second line
    for (int i=0;i<n;i++)   
    {
        fprintf(fp, ",");
    }


    // Doolittle
    double **L = MatrixGenerator(n, n);
    for (int i=0;i<n;i++)
    {
        L[i][i] = 1; // init L
    }
    double **U = MatrixGenerator(n, n);
    DoolittleDecom(n, A, L, U);


    do
    {
        // update Y
        for (int i=0;i<n;i++)
        {
            Y[i] = X[i]/lambda2;
            fprintf(fp, "%f,", Y[i]); // Output Y
        }
        fprintf(fp, "\n"); // line break
        lambda1 = lambda2;

        // calculate X
        GetYofLY(n, L, Y, UX);
        GetXofUX(n, U, UX, X);

        // get lambda2
        lambda2 = X[0];
        for (int i=1;i<n;i++)
        {
            if (fabs(X[i]) > fabs(lambda2))
            {
                lambda2 = X[i];
            }
        }
        
        k++;

        // Output result
        fprintf(fp, "%d,%f,", k, lambda2);
        for (int i=0;i<n;i++)   
        {
            fprintf(fp, "%f,", X[i]); // Output X
        }

    } while (fabs(lambda2 - lambda1) > epsilon);
    

    printf((0 == fclose(fp)) ? "Results saved successfully.\n" : "Results saving failed.");  

}

