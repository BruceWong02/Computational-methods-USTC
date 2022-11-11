/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : FFT.h
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-11-08 14:33:41
 * @Description : 
 * 
 * One dimensional FFT and IFFT package.
 * 
 ******************************************************************************/


#ifndef __FFT_H__
   #define __FFT_H__

   #include <stdio.h>
   #include <stdlib.h>
   #include <time.h>
   #include <complex.h>
   #include <math.h>


   /* Show Vector for debuging*/
   void Debug_ShowVector(int n, double complex *Vect, int exit_);

   /* 1D FFT while number of points is n=2^k 
      FFT(f) = g                              */
   void FFT(int n, double complex *f, double complex *g);

   /* 1D IFFT while number of points is n=2^k
      IFFT(f) = g                              */
   void IFFT(int n, double complex *f, double complex *g);

#endif


