// #include "mkl.h"
#include <cblas.h>
#include <cstdio>

const size_t M = 1000;
const size_t N = 756;
const size_t K = 64;

static float A[M][N];
static float B[N][K];
static float C[M][K];

int main(){
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            A[i][j] = 1.0f;
    }
    }
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            B[i][j] = 1.0f;
        }
    }

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                M, K, N, 1.0, *A, N, *B, K, 0.0, *C, K);

    // for (size_t i = 0; i < M; i++) {
    //     for (size_t j = 0; j < K; j++) {
    //         printf("%f, ", C[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}