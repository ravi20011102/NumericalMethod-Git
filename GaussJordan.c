#include <stdio.h>
#define N 3         // Number of variables

void display(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            float ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= N; k++) {
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            float ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= N; k++) {
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        float divisor = matrix[i][i];
        for (int j = 0; j <= N; j++) {
            matrix[i][j] = matrix[i][j] / divisor;
        }
    }
}

int main() {
    float matrix[N][N+1];

    printf("Enter the coefficients and constants : \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
    printf("Original Matrix:\n");
    display(matrix);

    gaussJordan(matrix);

    printf("\nMatrix after Gauss Jordan Method :\n");
    display(matrix);

    printf("\nThe solution of the system of linear equation is :\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][N]);
    }
    
    return 0;
}
