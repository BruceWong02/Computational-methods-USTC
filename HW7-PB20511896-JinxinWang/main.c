/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : main.c
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-11-23 18:29:51
 * @Description : 
 * 
 * The 8th homework of Computational Methods.
 * Using Romberg method to caculate numerical integration.
 * 
 ******************************************************************************/


#include "include/NumInte.h"


double e = 0.000001;
int n = 1;
int M = 8;

double ax(double t)
{
    return sin(t)/(1+sqrt(t));
}

double ay(double t)
{
    return log(1+t)/(1+t);
}

double vx(double t)
{
    return Romberg(ax, 0, t, n, M, e);
}

double vy(double t)
{
    return Romberg(ay, 0, t, n, M, e);
}


int main()
{
    double ts[100] = {0};
    for (int i=0;i<100;i++)
    {
        ts[i] = 0.1*(i+1);
    }

    char *fileOut = "v(t).csv";
    FILE * fp = fopen(fileOut, "w");
    if (NULL == fp){
        printf("Failed to open %s", fileOut);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%s,%s\n", "vx(t)", "vy(t)");
    for (int i=0;i<100;i++)
    {
        fprintf(fp, "%.7lf,%.7lf\n", vx(ts[i]), vy(ts[i]));
    }
    printf((0 == fclose(fp)) ? "File closed successfully.\n" : "Failed to close file.\n"); 
    

    char *fileOut1 = "r(t).csv";
    FILE * fp1 = fopen(fileOut1, "w");
    if (NULL == fp1){
        printf("Failed to open %s", fileOut1);
        exit(EXIT_FAILURE);
    }
    fprintf(fp1, "%s,%s\n", "x(t)", "y(t)");
    for (int i=0;i<100;i++)
    {
        fprintf(fp1, "%.7lf,%.7lf\n",Romberg(vx, 0, ts[i], n, M, e) , Romberg(vy, 0, ts[i], n, M, e));
    }
    printf((0 == fclose(fp1)) ? "File closed successfully.\n" : "Failed to close file.\n"); 


    return 0;
}