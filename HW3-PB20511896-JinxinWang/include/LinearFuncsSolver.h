/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : LinearFuncsSolver.h
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-09-17 11:52:20
 * @Description : Declare functions and constances; Include all heaeder files.
 *      
 *      In this file, two defined functions were all designed for solving system
 *      of linear functions in a special form:
 * 
 *      A*x = b
 *      A = [-(2*epsilon+h),    epsilon + h,                             ]
 *          [       epsilon, -(2*epsilon+h), epsilon+h,                  ]
 *          [              ,            ...,       ...,         epsilon+h]
 *          [                                    epsilon,  -(2*epsilon+h)]
 * 
 *      b[i] = a*h^2
 ******************************************************************************/

#ifndef __LINEARFUNCSSOLVER_H__
    #define __LINEARFUNCSSOLVER_H__


    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>

    /* Generate (n x m) Matrix */
    double** MatrixGenerator(int n, int m);

    /* Free memory used to generate Matrix */
    void FreeMatrixMemory(double **Matrix, int m);

    /* Fill elements of A1 */
    void FillA1(double **A1);

    /* Fill elements of A2 */
    void FillA2(double **A2);

    /* Doolittle Factorization */
    void DoolittleFactor(double **A, double **L, double **U);

    /*Using the Inverse Power Method to find 
        minimum eigenvalue of modulus and eigenvector */
    void MinEig_IPM(double **A, int n);

#endif
