#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.0001
float function(float x)
{
	return x*x*x-2*x-5;
}
int main(){
	float a, b, c, fa, fb, fc;
	int i=1;
	printf("Enter 1st guess : a = ");
	scanf("%f", &a);
	printf("Enter 2nd guess : b = ");
	scanf("%f", &b);
	printf("------------------------------------------------------------------");
	printf("\nIteration   a\t\tb\t\tc\t\tfa\t\tfb\t\tfc");
    do{
		fa = function(a);
		fb = function(b);
		c = (fb*a-fa*b)/(fb-fa);
		fc = function(c);
		printf("\n%d\t%f\t%f\t%f\t%f\t%f\t%f\n",i++, a, b, c, fa, fb, fc);
		a=b;
        b=c;
	}while(fabs(fc)>e);
	printf("\nThe root of the given function by secant method is %f",c);
	return 0;
}