#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    printf("Equation should be written in form of C(n) + a X C(n-1) + b X C(n-2) = 0\t\t\t----equation 1\n");
    float a1,a2,a,b,D;
    int n;
    printf("Enter the value of 'a' of equation 1 ");
    scanf("%f",&a);
    printf("Enter the value of 'b' of equation 2 ");
    scanf("%f",&b);
    printf("Enter rank/index of first term input ");
    scanf("%d",&n);
    printf("Enter the value of a%d ",n);
    scanf("%f",&a1);
    printf("Enter the value of a%d ",n+1);
    scanf("%f",&a2);
    D=pow(a,2)-4*b;
    if (D<0)
        printf("This equation has no recursive relation");
    else
    {
        float r1,r2;
        r1=(-a+sqrt(D))/2;
        r2=(-a-sqrt(D))/2;
        float u,v;
        if (r1!=r2)
        {
            v=(pow(r1,n+1)*a1-pow(r1,n)*a2)/(pow(r2,n)*pow(r1,n+1)-pow(r1,n)*pow(r2,n+1));
            u=(pow(r2,n+1)*a1-pow(r2,n)*a2)/(pow(r2,n+1)*pow(r1,n)-pow(r2,n)*pow(r1,n+1));
            printf("\n\nHence, nth term of recursive relation is %f X %f(rise to power n) + %f X %f(rise to power n) \n",u,r1,v,r2);
        }
        else
        {
            v=(a2-a1*r1)/pow(r1,n+1);
            u=(a1*(n+1)*r1-a2*n)/pow(r1,n+1);
            printf("\n\nHence, nth term of recursive relation is %f X %f(rise to power n) + %f X n X %f(rise to power n) \n",u,r1,v,r2);
        }

    }
}
