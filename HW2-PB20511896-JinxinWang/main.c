/**************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName: main.c
 * @Author: Bruce wong
 * @Version: 
 * @Date: 2022-09-17 11:52:20
 * @Description: 
 *************************************************************/

#include "./include/LinearFuncsSolver.h"

double epsilon;

int main()
{
    double A[100][100] = {0};
    double R[100][100] = {0};
    double h = 0.01;
    double a = 0.5;
    double epsilons[4] = {1., 0.1, 0.01, 0.0001};

    for (int k=0;k<4;k++)
    {
        epsilon = epsilons[k];
        printf("epsilon is: %f\n", epsilon);
        CalAccuSol(epsilon);
        GenerateMatrix(epsilon, -(2*epsilon+h), epsilon+h, A);
        GaussEliminationWithPartialPivoting(A);
        GenerateMatrix(epsilon/(2*epsilon+h), 0., (epsilon+h)/(2*epsilon+h), R);
        Gauss_SeidelIteration(R);
    }

    return 0;
}
