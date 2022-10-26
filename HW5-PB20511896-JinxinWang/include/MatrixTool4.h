/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : MatrixTool4.h
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-10-26 08:37:54
 * @Description : 
 * 
 * 
 * 
 ******************************************************************************/



#ifndef __MATRIXTOOL4_H__
    #define __MATRIXTOOL4_H__

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    #include <string.h>

    /* Show Matrix for debuging*/
    void Debug_ShowMatrix(int n, int m, double **M, int exit_);
    
    /* Show Vector for debuging*/
    void Debug_ShowVector(int n, double *Vect, int exit_);

    /* Generate (n x m) Matrix initiated with init() */
    double** MatrixGenerator(int n, int m, void(*init)(int, int, double**));

    /* Free memory used to generate Matrix */
    void FreeMatrixMemory(double **Matrix, int m);

    /* Initialize (n x m) matrix with same number */
    void MatrixInit_0(int n, int m, double **M);

    /* Initialize a vector whose elements are all the same */
    void VectInit_Same(int n, double *Vector, double value);

    /* A special situation of LU Factorization.
    国内称为追赶法，就是用LU分解求三对角方阵。 
    para:
    Mn3: (nx3) Matrix                                 */
    void Thomas(int n, double **Mn3, double *b,double *x);

    int fileLineNum(char *filename);

    /* Calculate M=S''(x) in Cubic Spline Interpolation.
    Need to de used with Thomas together       
    
    para:
    condition: 0 for natural boundary condition*/
    void Spline_M(char *filename, double *Ms, int condition);

#endif


