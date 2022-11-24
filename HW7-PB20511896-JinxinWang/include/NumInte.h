/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : NumInte.h
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-11-23 18:29:51
 * @Description : 
 * 
 * Numerical Integration package.
 * 
 ******************************************************************************/

#ifndef __NUMINTE_H__
   #define __NUMINTE_H__

   #include <stdio.h>
   #include <stdlib.h>
   #include <math.h>

   /* Use Romberg formula to caculate numerical integration 
   args:
      f: function
      a: start point
      b: end point
      M: times of iteration
      e: accuracy
   */
   double Romberg(double(*f)(double), double a, double b, int n, int M, double e);

#endif

