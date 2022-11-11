#include "../include/FFT.h"


void Debug_ShowVector(int n, double complex *Vect, int exit_)
{
    // for debug
    printf("Real:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f   ", creal(Vect[i]));
    }
    printf("\nImag:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f   ", cimag(Vect[i]));
    }
    printf("\n");
    if (1 == exit_){
        exit(EXIT_SUCCESS);
    }
}


void VectInit_Same(int n, double *Vector, double value)
{
    for (int i=0;i<n;i++){
        Vector[i] = value;
    }
}


void FFT(const int n, double complex *f, double complex *g)
{
    if (1==n){
        g[0] = f[0];
    }

    else{
        const int n_2 = n/2;
        // odd
        double complex f_odd[n_2];
        double complex g_odd[n_2];
        // oven
        double complex f_oven[n_2];
        double complex g_oven[n_2];

        // evaluate
        for (int i=0;i<n_2;i++){
            f_odd[i] = f[2*i+1];
            f_oven[i] = f[2*i];
        }

        // Calculate FFT of odd and oven
        FFT(n_2, f_odd, g_odd);
        FFT(n_2, f_oven, g_oven);

        double ome0 = -2*M_PI/n;
        double complex Omega_n = cexp(ome0*I);

        for (int i=0;i<n_2;i++){
            g[i] = (g_oven[i]+cpow(Omega_n,i)*g_odd[i])/2.0;
            g[i+n_2] = (g_oven[i]-cpow(Omega_n,i)*g_odd[i])/2.0;
        }

        // double flag = 1.0;
        // double ome1 = 0.;
        // for (int i=0;i<n_2;i++){
        //     flag = 1.0;
        //     ome1 = ome0*i;
        //     if (fabs(ome1)>=M_PI){
        //         ome1 = ome1>0 ? (ome1-M_PI) : (ome1+M_PI);
        //         flag = -1.0;
        //     }
        //     g[i] = (g_oven[i]+flag*cexp(ome1*I)*g_odd[i])/2;
        //     g[i+n_2] = (g_oven[i]-flag*cexp(ome1*I)*g_odd[i])/2;
        // }

    }    
}


void IFFT(int n, double complex *f, double complex *g)
{
    if (1==n){
        g[0] = f[0];
    }

    else{
        const int n_2 = n/2;
        // odd
        double complex f_odd[n_2];
        double complex g_odd[n_2];
        // oven
        double complex f_oven[n_2];
        double complex g_oven[n_2];

        // evaluate
        for (int i=0;i<n_2;i++){
            f_odd[i] = f[2*i+1];
            f_oven[i] = f[2*i];
        }

        // Calculate IFFT of odd and oven
        IFFT(n_2, f_odd, g_odd);
        IFFT(n_2, f_oven, g_oven);

        double ome0 = 2*M_PI/n;
        double complex Omega_n = cexp(ome0*I);

        for (int i=0;i<n_2;i++){
            g[i] = g_oven[i]+cpow(Omega_n,i)*g_odd[i];
            g[i+n_2] = g_oven[i]-cpow(Omega_n,i)*g_odd[i];
        }

        // double ome1 = 0.0;
        // double flag = 1.0;
        // for (int i=0;i<n_2;i++){
        //     flag = 1.0;
        //     ome1 = ome0*i;
        //     if (fabs(ome1)>=M_PI){
        //         ome1 = ome1>0 ? (ome1-M_PI) : (ome1+M_PI);
        //         flag = -1.0;
        //     }
        //     g[i] = g_oven[i]+flag*cexp(ome1*I)*g_odd[i];
        //     g[i+n_2] = g_oven[i]-flag*cexp(ome1*I)*g_odd[i];
        // }
    }    
}


