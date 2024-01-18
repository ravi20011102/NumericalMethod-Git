#include<stdio.h>
#include<stdio.h>
int main(){
    int a[10][10],c,i,j,p,q,m,n,k;
    printf("Enter the coefficients of x, y, z as well as constants : \n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        
        
        printf("The matrix is\n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
        return 0;
}

