/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : MatrixTool2.h
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-10-01 21:02:56
 * @Description : Declare functions; Include all heaeder files.
 *      
 *      Main functions including
 *          generate n x m Matrix padded with 0,
 *          Initiate all of n x m Matrix's elements to 0,
 *          Doolittle decomposition,
 *          Slove Y from LY=b where L is a lower trigonometric matrix,
 *          Slove X from UX=Y where U is a upper trigonometric matrix,
 *          Calculate the minimum eigenvalue of modulus and eigenvector by 
 *              Inverse Power Method.
 *      
 *      A1 and A2 are specific matrix defined in homework3.
 *      The input of A2 is though a txt file.
 ******************************************************************************/

#ifndef __MATRIXTOOL2_H__
    #define __MATRIXTOOL2_H__


    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>

    /* Generate (n x m) Matrix padded with 0 */
    double** MatrixGenerator(int n, int m);

    /* Free memory used to generate Matrix */
    void FreeMatrixMemory(double **Matrix, int m);

    /* Initialized (n x m) Matrix to 0 */
    void Init2Zero(int n, int m, double **M);

    /* Fill elements of A1 */
    void FillA1(double **A1);

    /* Fill elements of A2 from data file */
    void FillA2(double **A2);

    /* Doolittle Factorization 
        L = [1             ] 
            [*, 1          ]
            [ ...          ]
            [*, ...     , 1]
    */
    void DoolittleDecom(int n, double **A, double **L, double **U);

    /*Using the Inverse Power Method to find 
        minimum eigenvalue of modulus and eigenvector */
    void MinEig_IPM(char *filename, double **A, int n, double epsilon);

    /* Y=UX
        L(UX)=b <=> LY=b
        L = [*             ] 
            [*, *          ]
            [ ...          ]
            [*, ...     , *]
    */
    void GetYofLY(int n, double **L, double *b, double *Y);

    /* UX=Y */
    void GetXofUX(int n, double **U, double *Y, double *X);


#endif
