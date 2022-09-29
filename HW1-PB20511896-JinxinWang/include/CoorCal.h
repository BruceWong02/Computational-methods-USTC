/**************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName: CoorCal.h
 * @Author: Bruce wong
 * @Version: 
 * @Date: 2022-9-6 18:24
 * @Description: Declare functions and constances; Include all 
 * heaeder files.
 *************************************************************/

#ifndef __COORCAL_H__
#define __COORCAL_H__


#include <stdio.h>
#include <math.h>


// theta is the angle of vector OT and x negative semi-axis.

/*
Get coordinate of P or Q.
*/
void GetCoor();

/*
Calculate the derivative of Optical Path.
*/
double dL(double);

/*
Calculate coordinates of T and R by dichotomy.
*/
void CalTQ(double theta1, double theta2);


#endif