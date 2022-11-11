#include "../include/MatrixTool4.h"


void Debug_ShowMatrix(int n, int m, double **M, int exit_)
{
    // for debug
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%f   ", M[i][j]);
        }
        printf("\n");
    }
    if (1 == exit_){
        exit(EXIT_SUCCESS);
    }
}
    

void Debug_ShowVector(int n, double *Vect, int exit_)
{
    // for debug
    for (int i = 0; i < n; i++)
    {
        printf("%f   ", Vect[i]);
    }
    printf("\n");
    if (1 == exit_){
        exit(EXIT_SUCCESS);
    }
}


double** MatrixGenerator(int n, int m, void(*Init)(int, int, double**))
{
    // detect input error
    if (n<=0 || m<=0){
        printf("Matrix parameters input error!!!");
        exit(EXIT_FAILURE);
    }

    // generate Matrix with malloc
    double **Matrix = (double **)malloc(sizeof(double *)*n);
    for (int i=0;i<n;i++){
        Matrix[i] = (double *)malloc(sizeof(double)*m);
    }

    Init(n, m, Matrix);

    return Matrix;
}


void FreeMatrixMemory(double **Matrix, int n)
{
    for (int i=0;i<n;i++){
        free(Matrix[i]);
    }
    free(Matrix);
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


void Thomas(int n, double **Mn3, double *b, double *x)
{
    const int num = n;
    double u = 0.;
    double v[num];
    v[0] = 0.;
    double y[num];
    y[0] = b[0]/Mn3[0][1];

    for (int i=1;i<num;i++){
        u = Mn3[i][1] - Mn3[i][0]*v[i-1];
        v[i] = Mn3[i][2]/u;
        y[i] = (b[i]-Mn3[i][0]*y[i-1])/u;
    }
    x[n-1] = y[n-1];
    for (int i=(n-2);i>=0;i--){
        x[i] = y[i] - v[i]*x[i+1];
    }
}


int fileLineNum(char *filename)
{
    // Read Datas
    FILE * fp = fopen(filename, "r");
    if (NULL == fp){
        printf("Failed to open %s", filename);
        exit(EXIT_FAILURE);
    }

    int count = 1;
    char termc;
    while ((termc=getc(fp)) != EOF){
        if (termc == '\n'){
            count++;
        }
    }

    printf((0 == fclose(fp)) ? "File closed successfully.\n" : "Failed to close file.\n"); 
    
    return count;
}


void Spline_M(char *filename, double *Ms, int condition)
{
    // Read Datas
    FILE * fp = fopen(filename, "r");
    if (NULL == fp){
        printf("Failed to open %s", filename);
        exit(EXIT_FAILURE);
    }

    int count = fileLineNum(filename);

    const int nPoints = count;
    int x[nPoints];
    double y[nPoints];
    for (int i=0;i<nPoints;i++){
        fscanf(fp, "%d\t%lf", &x[i], &y[i]);
    }

    printf((0 == fclose(fp)) ? "File closed successfully.\n" : "Failed to close file.\n"); 


    // set of linear functions
    // A*xM = b
    double **A = MatrixGenerator(nPoints-2, 3, MatrixInit_0);
    double M[nPoints];
    double xM[nPoints-2];
    double b[nPoints-2];

    double mu[nPoints-1];
    double lambda[nPoints-1];
    double d[nPoints-1];
    double h[nPoints-1];

    h[0] = x[1] - x[0];
    for (int i=1;i<(nPoints-1);i++){
        h[i] = x[i+1] - x[i];
        lambda[i] = h[i] / (h[i]+h[i-1]);
        mu[i] = 1 - lambda[i];
        d[i] = 6 * ((y[i+1]-y[i])/h[i] - (y[i]-y[i-1])/h[i-1]) / (h[i] + h[i-1]);
    }

    // natural boundary condition
    if (0==condition){
        for (int i = 1; i < (nPoints-1); i++){
            A[i-1][0] = mu[i];
            A[i-1][1] = 2;
            A[i-1][2] = lambda[i];
            b[i-1] = d[i];
        }
    }
    
    // Debug_ShowVector(nPoints-2, b, 1);
    // Debug_ShowMatrix(nPoints-2, 3, A, 1);

    Thomas(nPoints-2, A, b, xM);

    M[0] = 0.;
    for (int i=1;i<(nPoints-1);i++){
        M[i] = xM[i-1];
    }
    M[nPoints-1] = 0.;


    // homework requirement
    // Read Datas
    char fileOut[strlen(filename)-4];
    for (int i=0;i<(strlen(filename)-4);i++){
        fileOut[i] = filename[i];
    }
    strcat(fileOut, ".csv");
    FILE * fp3 = fopen(fileOut, "w");
    if (NULL == fp3){
        printf("Failed to open %s", fileOut);
        exit(EXIT_FAILURE);
    }

    double a1 = 0.;
    double a2 = 0.;
    double a3 = 0.;
    double a4 = 0.;
    printf("\n");
    for (int i=0;i<(nPoints-1);i++){
        a1 = (M[i+1]-M[i])/(6*h[i]);
        a2 = (x[i+1]*M[i]-x[i]*M[i+1])/(2*h[i]);
        a3 = (3*(x[i]*x[i]*M[i+1]-x[i+1]*x[i+1]*M[i])+
            6*(y[i+1]-y[i])-h[i]*h[i]*(M[i+1]-M[i]))/(6*h[i]);
        a4 = (x[i+1]*x[i+1]*x[i+1]*M[i]-x[i]*x[i]*x[i]*M[i+1]+
            6*(x[i+1]*y[i]-x[i]*y[i+1])-h[i]*h[i]*(x[i+1]*M[i]-x[i]*M[i+1]))
            /(6*h[i]);
        printf("[%d, %d]: S{%d}=", x[i], x[i+1], i);
        printf("(%f)*x^3 + ", a1);
        printf("(%f)*x^2 + ", a2);
        printf("(%f)*x + ", a3);
        printf("(%f)\n", a4);

        fprintf(fp3, "%lf,%lf,%lf,%lf\n", a1, a2, a3, a4);
    }
    printf("\n");

    printf((0 == fclose(fp3)) ? "File closed successfully.\n" : "Failed to close file.\n"); 

    FreeMatrixMemory(A, nPoints-2);
}



