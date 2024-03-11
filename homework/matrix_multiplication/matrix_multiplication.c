#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include "cblas.h"

// Function to generate a random matrix of given dimensions
void generateRandomMatrix(double* matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i * cols + j] = (double)rand() / RAND_MAX * 10;  // Random value between 0 and 10
        }
    }
}

// Function to print a matrix
void printMatrix(double* matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s matrix_dimension\n", argv[0]);
        return 1;
    }

    int dim = atoi(argv[1]);  // Get matrix dimension from command line argument

    double* A = (double*)malloc(dim * dim * sizeof(double));
    double* B = (double*)malloc(dim * dim * sizeof(double));
    double* C = (double*)malloc(dim * dim * sizeof(double));

    srand(time(NULL));  // Seed for random number generation

    generateRandomMatrix(A, dim, dim);
    generateRandomMatrix(B, dim, dim);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, dim, dim, dim, 1, A, dim, B, dim, 0, C, dim);

    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);

    printf("Matrix multiplication time: %.2f microseconds\n", time_taken);

    // Print the result matrix if needed
    // printMatrix(C, dim, dim);

    free(A);
    free(B);
    free(C);

    return 0;
}
