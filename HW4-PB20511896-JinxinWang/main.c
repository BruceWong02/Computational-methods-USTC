/*******************************************************************************
 * @Coding: UTF-8
 * @copyright (C), 2022, Bruce Wong, All rights reserved.
 * @FileName    : main.c
 * @Author      : Bruce wong
 * @Version     : 
 * @Date        : 2022-10-09 16:34:52
 * @Description : 
 * 
 * The fourth Computational Methods program homework.
 * 
 * (a) Generate a random 4x3 matrix A, where each element of A is a random 
 * number in [0, 1]. Use Jacobi method to solve eigvalues of A*A^{T} and 
 * calculate SVD decomposition of A.
 * 
 * (b) Apply PCA to "iris" data sets concluding 150 datas and visualize their 
 * distribution at top two main directions. 
 * Each data has 4 attributions and a lable. The lable's value is 0, 1 or 2. 
 * Datas with different lable need to be distingushed by different color or shape.
 * 
 ******************************************************************************/


#include "include/MatrixTool3.h"


int main(){
    double epsilon = 0.000001;

    // (a)
    double **A = MatrixGenerator(4, 3, MatrixInit_Rand_0_1);
    double **U = MatrixGenerator(4, 4, MatrixInit_0);
    double **Sigma = MatrixGenerator(4, 3, MatrixInit_0);
    double **VT = MatrixGenerator(3, 3, MatrixInit_0);
    SVD(4, 3, A, U, Sigma, VT, epsilon);

    printf("A = U Sigma VT :\n");
    for (int i=0;i<4;i++){
        printf("[");
        for (int j=0;j<3;j++){
            printf("%f   ", A[i][j]);
        }
        printf("\b\b\b]");

        printf((1==i ? " = " : "   "));

        printf("[");
        for (int j=0;j<4;j++){
            printf("%f   ", U[i][j]);
        }
        printf("\b\b\b][");

        for (int j=0;j<3;j++){
            printf("%f   ", Sigma[i][j]);
        }
        printf("\b\b\b][");

        if (3==i){
            printf("\b \n\n");
        }
        else {
            for (int j=0;j<3;j++){
                printf("%f   ", VT[i][j]);
            }
            printf("\b\b\b]\n");
        }
    }
    
    FreeMatrixMemory(A, 4);
    FreeMatrixMemory(U, 4);
    FreeMatrixMemory(Sigma, 4);
    FreeMatrixMemory(VT, 3);

    // (b)
    double **IrisDatas = MatrixGenerator(4, 150, MatrixInit_0);
    double **FinalM = MatrixGenerator(2, 150, MatrixInit_0);
    int labels[150];
    char *filename = "iris.txt";

    // Read Datas
    FILE * fp = fopen(filename, "r");
    if (NULL == fp){
        printf("fopen() failed!!!");
        exit(EXIT_FAILURE);
    }
    for (int i=0;i<150;i++){
        fscanf(fp, "%lf,%lf,%lf,%lf,%d", &IrisDatas[0][i], &IrisDatas[1][i], &IrisDatas[2][i], &IrisDatas[3][i], &labels[i]);
    }
    printf((0 == fclose(fp)) ? "File closed successfully.\n" : "Failed to close file."); 


    PCA(4, 150, IrisDatas, epsilon, 2, FinalM);

    // Create output file.
    char *filename1 = "result.csv";
    FILE * fp1 = fopen(filename1, "w+");
    if (NULL == fp1){
        printf("fopen() failed!!!");
        exit(EXIT_FAILURE);
    }
    // Output result
    for (int i=0;i<150;i++){
        fprintf(fp1, "%f,%f,%d\n", FinalM[0][i], FinalM[1][i], labels[i]);
    }

    printf((0 == fclose(fp1)) ? "Results saved successfully.\n" : "Results saving failed.");  


    FreeMatrixMemory(FinalM, 2);
    FreeMatrixMemory(IrisDatas, 4);
    
    return 0;
}



