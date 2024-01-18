#include <stdio.h>
#define N 3             // Number of variables

void display(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussElimination(float matrix[N][N + 1]) {
    for (int i = 0; i < N - 1; i++) {
        for (int k = i + 1; k < N; k++) {
            float factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= N; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

void backSubstitution(float matrix[N][N + 1], float solution[N]) {
    for (int i = N - 1; i >= 0; i--) {
        solution[i] = matrix[i][N];
        for (int j = i + 1; j < N; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
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

    gaussElimination(matrix);

    printf("\nMatrix after Gaussian Elimination Method :\n");
    display(matrix);

    float solution[N];
    backSubstitution(matrix, solution);

    printf("\nThe solution of the system of linear equation is :\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }

    return 0;
}
