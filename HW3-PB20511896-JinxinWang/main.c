/**************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName: main.c
 * @Author: Bruce wong
 * @Version: 
 * @Date: 2022-10-01 21:02:56
 * @Description: 
 *************************************************************/

#include "./include/MatrixTool2.h"


int main()
{
    double **A1, **A2;

    A1 = MatrixGenerator(5, 5);
    A2 = MatrixGenerator(4, 4);
    FillA1(A1);
    FillA2(A2);

    MinEig_IPM(A1, 5, 0.00001);
    MinEig_IPM(A2, 4, 0.00001);

    FreeMatrixMemory(A1, 5);
    FreeMatrixMemory(A2, 4);

    return 0;
}
