/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : main.c
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-11-08 14:31:09
 * @Description : 
 * 
 * The 6th Computational Methods homework. 
 * 
 * Using FFT and IFFT to analyze given functions.
 * 
 ******************************************************************************/


#include "include/FFT.h"


double complex f1_x(double x)
{
    return 0.7*sin(2*M_PI*2*x) + sin(2*M_PI*5*x);
}


double complex f2_x(double x)
{
    // set random number seed
    srand((unsigned) time(NULL));
    double randNum = (double)rand() / (double)RAND_MAX;
    return 0.7*sin(2*M_PI*2*x) + sin(2*M_PI*5*x) + 0.3*randNum;
}


int main(){
    // const int n1 = 16;
    // const int n2 = 128;
    // const int n2_25 = 32;

    double complex f1_1[16] = {0.};
    double complex f1_2[128] = {0.};
    double complex f2[128] = {0.};

    double complex g1_1[16] = {0.};
    double complex g1_2[128] = {0.};
    double complex g2[128] = {0.};
    double complex g2_25[128] = {0.};

    double complex F1_1[16] = {0.};
    double complex F1_2[128] = {0.};
    double complex F2[128] = {0.};
    double complex F2_25[128] = {0.};

    for (int i=0;i<16;i++){
        f1_1[i] = f1_x((double)i/16);
    }
    for (int i=0;i<128;i++){
        f1_2[i] = f1_x((double)i/128);
        f2[i] = f2_x((double)i/128);
    }

    FFT(16, f1_1, g1_1);
    FFT(128, f1_2, g1_2);
    FFT(128, f2, g2);
    for (int i=0;i<32;i++){
        g2_25[i] = g2[i];
    }

    IFFT(16, g1_1, F1_1);
    IFFT(128, g1_2, F1_2);
    IFFT(128, g2, F2);
    IFFT(128, g2_25, F2_25);
    

    // f1 n1
    char *fileOut1 = "f1_n1.csv";
    FILE * fp1 = fopen(fileOut1, "w");
    if (NULL == fp1){
        printf("Failed to open %s", fileOut1);
        exit(EXIT_FAILURE);
    }
    fprintf(fp1, "%s,%s,%s,%s,%s,%s,%s\n", 
            "k", "f", "Real(g)", "Imag(g)", "Abs(g)", "Real(IFFT(g))", "Imag(IFFT(g))");
    for (int i=0;i<16;i++){
        fprintf(fp1, "%d,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf\n", 
            i, creal(f1_1[i]), creal(g1_1[i]), cimag(g1_1[i]), cabs(g1_1[i]), creal(F1_1[i]), cimag(F1_1[i]));
    }
    printf((0 == fclose(fp1)) ? "File closed successfully.\n" : "Failed to close file.\n"); 

    // f1 n2
    char *fileOut2 = "f1_n2.csv";
    FILE * fp2 = fopen(fileOut2, "w");
    if (NULL == fp2){
        printf("Failed to open %s", fileOut2);
        exit(EXIT_FAILURE);
    }
    fprintf(fp2, "%s,%s,%s,%s,%s,%s,%s\n", 
            "k", "f", "Real(g)", "Imag(g)", "Abs(g)", "Real(IFFT(g))", "Imag(IFFT(g))");
    for (int i=0;i<128;i++){
        fprintf(fp2, "%d,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf\n", 
            i, creal(f1_2[i]), creal(g1_2[i]), cimag(g1_2[i]), cabs(g1_2[i]), creal(F1_2[i]), cimag(F1_2[i]));
    }
    printf((0 == fclose(fp2)) ? "File closed successfully.\n" : "Failed to close file.\n"); 

    // f2 n2
    char *fileOut3 = "f2_n2.csv";
    FILE * fp3 = fopen(fileOut3, "w");
    if (NULL == fp3){
        printf("Failed to open %s", fileOut3);
        exit(EXIT_FAILURE);
    }
    fprintf(fp3, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n", 
            "k", "f", "Real(g)", "Imag(g)", "Abs(g)", "Real(IFFT(g))", "Imag(IFFT(g))", "Real(IFFT(g'))", "Imag(IFFT(g'))");
    for (int i=0;i<128;i++){
        fprintf(fp3, "%d,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf,%.23lf\n", 
            i, creal(f2[i]), creal(g2[i]), cimag(g2[i]), cabs(g2[i]), creal(F2[i]), cimag(F2[i]), creal(F2_25[i]), cimag(F2_25[i]));
    }
    printf((0 == fclose(fp3)) ? "File closed successfully.\n" : "Failed to close file.\n"); 

    return 0;
}


