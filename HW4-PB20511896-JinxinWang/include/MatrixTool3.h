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

    /* Initialized (n x m) Matrix with random number in [0, 1] */
    void InitRand_0_1(int n, int m, double **Matrix);

    // 
    /* Caluculate eigvalues by Jacobi method */
    void Eigvalue_Jacobi(int n, double **Matrix, double *Eigvalues);

    // 
    /* Solve system of linear functions by Gauss-Seidel Iteration */
    void Gauss_Seidel_iter(int n, double **Matrix, double *X, double *Y);

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

    // 
    /* Generate a vector whose elements are all the same */
    void VectGener_Same(int n, double value);

#endif


