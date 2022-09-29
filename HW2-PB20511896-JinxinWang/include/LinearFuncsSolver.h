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

    #ifndef Max
        #define Max(a,b) (((a) > (b)) ? (a) : (b))
    #endif

    #include <stdio.h>
    #include <math.h>

    /* Use Gauss elimination with partial pivoting. */
    void GaussEliminationWithPartialPivoting(double A[100][100]);

    /* Use Gauss-Seidel iteration. */
    void Gauss_SeidelIteration(double R[100][100]);

    /* Permute two elements*/
    void Permuting(double, double);

    /* Generate 100x100 tridiagonal square matrix.*/
    void GenerateMatrix(double Down, double Mid, double Up, double A[100][100]);

    /* Generate Vector b whose components have the same value.*/
    void GenerateVector(double b[100], double value);

    /* Calculate distance between vector x1 and vector x0.*/
    double Distance(double X1[100], double X0[100]);

    /* Calculate accurate solution.*/
    void CalAccuSol(double epsilon);

#endif
