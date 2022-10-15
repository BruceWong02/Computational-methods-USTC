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
    #include <time.h>


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

    /* Matrix mutiply. Matrix3 = (nxm)Matrix1 * (mxn)Matrix2 */
    void MatrixMutiply(int n, int m, double **Matrix1, double **Matirx2, double **Matrix3);

    /*
    Solve system of linear functions by Gauss-Seidel Iteration

    pars:
        Ax=b => x = (I - D^{-1}A)x + D^{-1}b
        let M=I-D^{-1}A   b=D^{-1}b => x=Mx+b
    */
    void Gauss_Seidel_iter(int n, double **A, double *X, double *b, double delta);

    // 
    /* Caluculate eigvalues by Jacobi method */
    void Eigvalue_Jacobi(int n, double **Matrix, double *Eigvalues);

    // 
    /*
    Calculate one eigvector of Matrix with a known eigvalue.
    Here we transform the quetion to calculate the solution of a system of linear functions.

    pars:
        solver() is used to solve system of linear functions.
    */
    void Eigvector(int n, double **Matrix, double *Eigvector,
                    void(*solver)(int, double**, double*, double*));

    // 
    /* SVD decomposition */
    void SVD();



#endif


