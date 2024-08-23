#include "mkl.h"
// #include <cblas.h>
#include <cstdio>

const size_t M = 1000;
const size_t N = 756;
const size_t K = 64;

static float A[M][N];
static float B[N][K];
static float C[M][K];

template <size_t M, size_t N, size_t K>
void dot(float (&a)[M][N], float (&b)[N][K], float (&result)[M][K]) {
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
              M, K, N, 1.0, *a, N, *b, K, 0.0, *result, K);
}

int main(){
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            A[i][j] = i;
    }
    }
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            B[i][j] = i;
        }
    }

    dot(A, B, C);

    // for (size_t i = 0; i < M; i++) {
    //     for (size_t j = 0; j < K; j++) {
    //         printf("%f, ", C[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}