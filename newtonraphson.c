#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.0001
float function(float x)
{
	return x*x-3;		//change the function
}
float derivfunction(float x)
{
	return 2*x;			//derivative of the above function 
}
int main(){
	float x, fx, dfx, x_n;
	int i=1;
	up:
	printf("Enter the initial guess x = ");
	scanf("%f",&x);
	dfx = derivfunction(x);
	if(dfx==0)
		goto up;
		printf("------------------------------------------------------------------");
		printf("\nIteration   x_n\t\tfx\t\tdfx\t\tx_n+1");
		do{
			fx = function(x);
			dfx = derivfunction(x);
			x_n = x;
			x = x-(fx/dfx);
			printf("\n%d\t%f\t%f\t%f\t%f\n",i++,x_n,fx,dfx,x);
	}while(fabs(fx)>e);
	printf("\nThe root of the given function by Newton Raphson method is %f",x);
	return 0;
}
