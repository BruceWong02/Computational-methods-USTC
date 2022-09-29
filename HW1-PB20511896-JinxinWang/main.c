/**************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName: main.c
 * @Author: Bruce wong
 * @Version: 
 * @Date: 2022-9-6 18:24
 * @Description: Solving Cylindrical Specular Problem.
 *************************************************************/

#include "./include/CoorCal.h"

// coordinates of P and Q.
double P[2] = {0., 0.}; // Observer P
double Q[2] = {0., 0.}; // Object Q
double T[2] = {}; // reflection point T
double R[2] = {}; // object image point R


int main()
{
    GetCoor();
    CalTQ(0., 90.);
    printf("T = (%lf, %lf)\nQ = (%lf, %lf)", T[0], T[1], R[0], R[1]);
    return 0;
}
