/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : main.c
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-10-25 15:21:30
 * @Description : 
 * 
 * The fifth Computational Methods program homework.
 * 
 * There are information of 21 Briquetted Irons in "point.txt"
 * (a) Calculate curved line of Cubic Spline Interpolation
 * 
 * (b)change position of 10th briquetted iron to (0,10) and calculate new 
 *  curved line while observing the change of cubic function in each interval.
 * 
 ******************************************************************************/



#include "include/MatrixTool4.h"


int main(){
    double epsilon = 0.000001;

    
    // (a)
    char *filename = "point.txt";
    const int nPoints = fileLineNum(filename);
    double Ms[nPoints];
    Spline_M(filename, Ms, 0);

    // ****************************************************
    // (b)
    char *filename2 = "point_b.txt";
    const int nPoints2 = fileLineNum(filename2);
    double Ms2[nPoints2];
    Spline_M(filename2, Ms2, 0);

    return 0;
}



