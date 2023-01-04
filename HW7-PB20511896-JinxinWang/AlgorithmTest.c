/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : AlgorithmTest.c
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-11-24 08:05:00
 * @Description : 
 * 
 * The 8th homework of Computational Methods.
 * Compare algorithm with different parameters.
 * 
 ******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double e = 0.000001;
int n = 1;
int M = 8;

int HitTimes[5] = {0, 0, 0, 0, 0};

double Romberg_VBeta(double(*f)(double), double a, double b, int n, int M, int flag);

double ax(double t)
{
    return sin(t)/(1+sqrt(t));
}

double vx(double t, int M, int flag)
{
    return Romberg_VBeta(ax, 0, t, n, M, flag);
}


int main()
{
    double ts[100] = {0};
    for (int i=0;i<100;i++)
    {
        ts[i] = 0.1*(i+1);
    }

    int Ms[5] = {4, 8, 12, 16, 20};

    char *fileOut = "Times(Vx).csv";
    FILE * fp = fopen(fileOut, "w");
    if (NULL == fp){
        printf("Failed to open %s", fileOut);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s,%s,%s,%s,%s\n", "M=4", "M=8", "M=12", "M=16", "M=20");
    for (int i=0;i<100;i++)
    {
        fprintf(fp, "%.7lf,%.7lf,%.7lf,%.7lf,%.7lf\n", 
            vx(ts[i], Ms[0], 0), vx(ts[i], Ms[1], 1), vx(ts[i], Ms[2], 2), vx(ts[i], Ms[3], 3), vx(ts[i], Ms[4], 4));
    }


    printf((0 == fclose(fp)) ? "File closed successfully.\n" : "Failed to close file.\n"); 
    

    printf("M\t4\t \t8\t \t12\t \t16\t \t20\nRate\t");
    printf("%.7lf\t%.7lf\t%.7lf\t%.7lf\t%.7lf\n", 
        HitTimes[0]/100., HitTimes[1]/100., HitTimes[2]/100., HitTimes[3]/100., HitTimes[4]/100.);

    return 0;
}


double Romberg_VBeta(double(*f)(double), double a, double b, int n, int M, int flag)
{
    double h = b-a;
    double hk = 0.0;

    // times of iteration
    const int m = M;
    int final_k = 0;

    double R[m][m];
    R[0][0] = (f(a)+f(b))*h/2.;

    for (int k=1;k<m;k++)
    {
        final_k = k;

        hk = h/pow(2, k);
        double iMax = pow(2, k-1);

        R[k][0] = 0.;
        for (int i=0;i<iMax;i++)
        {
            R[k][0] = R[k][0] + f(a+(2*i+1)*hk);
        }
        R[k][0] = R[k-1][0]/2 + hk*R[k][0];

        for (int j=1;j<k+1;j++)
        {
            R[k][j] = R[k][j-1] + (R[k][j-1]-R[k-1][j-1])/(pow(4, j)-1);
        }

        if (fabs(R[k][k]-R[k-1][k-1]) < e)
        {
            HitTimes[flag]++;
            return (double)(final_k+1)/(double)(m);
        }
    }

    return 0.;
}

