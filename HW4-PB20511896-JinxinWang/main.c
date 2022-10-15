/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : main.c
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-10-09 16:34:52
 * @Description : 
 * 
 * The fourth Computational Methods program homework.
 * 
 * (a) Generate a random 4x3 matrix A, where each element of A is a random 
 * number in [0, 1]. Use Jacobi method to solve eigvalues of A*A^{T} and 
 * calculate SVD decomposition of A.
 * 
 * (b) Apply PCA to "iris" data sets concluding 150 datas and visualize their 
 * distribution at top two main directions. 
 * Each data has 4 attributions and a lable. The lable's value is 0, 1 or 2. 
 * Datas with different lable need to be distingushed by different color or shape.
 * 
 ******************************************************************************/


#include "include/MatrixTool3.h"

int main(){
    // (a)
    double **A = MatrixGenerator(4, 3, MatrixInit_Rand_0_1);
    double **AAT = MatrixGenerator(4, 4, MatrixInit_0);
    double AAT_eigvalue[4];

    // MatrixMutiply(4, 3, A, );
    Eigvalue_Jacobi(4, AAT, AAT_eigvalue);
    



    return 0;
}