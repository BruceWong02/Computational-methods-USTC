/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : MatrixTool3.h
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-10-09 16:56:03
 * @Description : 
 * 
 * Main functions including
 *      generate n x m Matrix padded with 0,
 *      Initiate all of n x m Matrix's elements to 0,
 *      Doolittle decomposition,
 *      Slove Y from LY=b where L is a lower trigonometric matrix,
 *      Slove X from UX=Y where U is a upper trigonometric matrix,
 *      Calculate the minimum eigenvalue of modulus and eigenvector by 
 *          Inverse Power Method.
 * 
 ******************************************************************************/


#ifndef __MATRIXTOOL3_H__
    #define __MATRIXTOOL3_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>

    /* Show Matrix for debuging*/
    void Debug_ShowMatrix(int n, int m, double **M, int exit_);
    
    /* Show Vector for debuging*/
    void Debug_ShowVector(int n, double *Vect, int exit_);

    /* Generate (n x m) Matrix initiated with init() */
    double** MatrixGenerator(int n, int m, void(*init)(int, int, double**));

    /* Free memory used to generate Matrix */
    void FreeMatrixMemory(double **Matrix, int m);

    /* Initialized (n x m) matrix with random number in [0, 1] */
    void MatrixInit_Rand_0_1(int n, int m, double **Matrix);

    /* Initialize (n x m) matrix with same number */
    void MatrixInit_0(int n, int m, double **M);

    /* Initialize a vector whose elements are all the same */
    void VectInit_Same(int n, double *Vector, double value);

    /* Calculate distance between vector x1 and vector x0.*/
    double Distance(int n, double *X1, double *X0);

    /* Normalize Vector */
    void VectNorm(int n, double *Vector);

    /* Matrix mutiply. Matrix3 = (nxm)Matrix1 * (mxn)Matrix2 */
    void MatrixMutiply(int n, int m, double **Matrix1, double **Matirx2, double **Matrix3);

    /* (nxm) Matrix Transpose */
    void MatrixTranspose(double n, double m, double **Matrix, double **MatrixT);

    /* Use Gauss elimination with partial pivoting. 
    
    pars:
        DetIs0: Is DetA 0? 0 for DetA != 0; 1 for DetA == 0; -1 for Auto Juage.
            Input not included above will result in Error report.              */
    void GaussElim_PartialPivoting(int n, double **A, double *X, double *b, int DetIs0);

    /*  Solve system of linear functions by Gauss-Seidel Iteration
    pars:
        Ax=b => x = (I - D^{-1}A)x + D^{-1}b
        let M=I-D^{-1}A   b=D^{-1}b => x=Mx+b                   */
    void Gauss_Seidel_iter(int n, double **A, double *X, double *b, double delta);

    /* Caluculate eigvalues by Jacobi method */
    void Eigvalue_Jacobi(int n, double **Matrix, double *Eigvalues, double epsilon);

    /*  Calculate one eigvector of Matrix with a known eigvalue directly.
    Here we transform the quetion to calculate the solution of a system 
    of linear functions.

    pars:
        solver() is used to solve system of linear functions.           */
    void Eigvector(int n, double **Matrix, double *Eigvectors, double EigValue, 
                    void(*solver)(int, double**, double*, double*, int));

    /*  Calculate one eigvector of Matrix with a known eigvalue by a iterational method.
    Here we transform the quetion to calculate the solution of a system 
    of linear functions.

    pars:
        solver() is used to solve system of linear functions.           */
    void Eigvector_iter(int n, double **Matrix, double *Eigvectors, double EigValue, double epsilon,
                    void(*solver)(int, double**, double*, double*, double));

    /* SVD decomposition */
    void SVD(int n, int m, double **A, double **U, double **Sigma, 
            double **VT, double epsilon);

    /* PCA projection 
    
    Pars:
        NeedBuffer: Buffer here is used as a copy of original Matrix in order to 
        make sure original Matrix won't be changed after this process. You can also 
        change original Matrix if you want.
        1 for buffer, others for no.                                            */
    void PCA(int n, int m, double **M, double epsilon, int FinalDim, double **FinalM, int NeedBUffer);


#endif


