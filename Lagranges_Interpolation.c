#include <stdio.h>
#include <math.h>
#include <conio.h>
int main(){
    int n, i, j;
    float x[10], fx[10], x1, sum = 0.0;
    printf("Enter the no. of terms n : ");
    scanf("%d", &n);
    printf("Enter the respective values of x0 to xn and f0 to fn : \n");
    for (i = 0; i < n; i++){
        printf("x%d = ", i);
        scanf("%f", &x[i]);
        printf("f(%.1f) = ", x[i]);
        scanf("%f", &fx[i]);
    }
    printf("Enter the value of x to find the respective function value : ");
    scanf("%f", &x1);
    for (i = 0; i < n; i++){
        float p = 1;
        for (j = 0; j < n; j++){
            if (j != i){
                p = p * ((x1 - x[j]) / (x[i] - x[j]));
            }
        }
        sum = sum + (fx[i] * p);
    }
    printf("f(%.2f) = %.2f\n", x1, sum);
    return 0;
}