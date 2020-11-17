#include <stdio.h>
#include <stdlib.h>

void aUb(int a[20],int b[20],int na, int nb)
{
 int c[40];
 int nc=0,count=0,ca=0,cb=0;
 c[nc++]=a[0];
 for(int i=0;i<na;i++)
 {

     for(int j=0;j<nb;j++)
     {
         ca=0;
         cb=0;
         if(a[i]!=b[j])
            {
                for(int k=0;k<nc;k++)
                {
                    if(c[k]!=a[i])
                        ca++;
                    if(c[k]!=b[j])
                        cb++;
                }
            }
         if(ca==nc && ca!=0)
            {
                if(cb==nc)
                    cb++;
                c[nc++]=a[i];
            }
         if(cb==nc)
            c[nc++]=b[j];
     }
}
for(int i=0;i<nc;i++)
   printf("%d  ",c[i]);
}
void diff(int a[20],int b[20],int na, int nb)
{
    int c[20],count,nc=0;
    for(int i=0;i<na;i++)
    {
        count=0;
        for(int j=0;j<nb;j++)
        {
            if(a[i]==b[j])
                {
                    count=1;
                    break;
                }
        }
        if(count==0)
        {
            c[nc++]=a[i];
        }
    }
    for(int i=0;i<nc;i++)
        printf("%d  ",c[i]);

}
void difference(int a[20],int b[20],int na, int nb)
{
    int t;
    printf("Enter 1 for A-B\nEnter 2 for B-A\nEnter choice : ");
    scanf("%d",&t);
    if(t==1)
        diff(a,b,na,nb);
    else
        diff(b,a,nb,na);
}
void intersection(int a[20],int b[20],int na, int nb)
{
    int c[20],count=0,nc=0;
    for(int i=0;i<na;i++)
    {
        count=0;
        for(int j=0;j<nb;j++)
        {
            if(a[i]==b[j])
                {
                    count=1;
                    break;
                }
        }
        if(count==1)
        {
            c[nc++]=a[i];
        }
    }
    for(int i=0;i<nc;i++)
        printf("%d  ",c[i]);
}

void adding(int a[20],int b[20],int na,int nb)
{
    int c[40],nc=0;
    for(int i=0;i<na;i++)
        c[nc++]=a[i];
    for(int i=0;i<nb;i++)
        c[nc++]=b[i];
    for(int i=0;i<nc;i++)
        printf("%d ",c[i]);
}

void symmertri_diff(int a[20],int b[20],int na,int nb)
{
    int c[40],nc=0,count=0;
    for(int i=0;i<na;i++)
    {
        count=0;
        for(int j=0;j<nb;j++)
        {
            if(a[i]==b[j])
                {
                    count=1;
                    break;
                }
        }
        if(count==0)
            c[nc++]=a[i];
    }
    for(int i=0;i<nb;i++)
    {
        count=0;
        for(int j=0;j<na;j++)
        {
            if(b[i]==a[j])
                {
                    count=1;
                    break;
                }
        }
        if(count==0)
            c[nc++]=b[i];
    }
    for(int i=0;i<nc;i++)
        printf("%d ",c[i]);
}

int main()
{
    printf("MADE BY GAURAV \t COE-2 \t 2019UCO1652 \n");
    int a[20],b[20],na,nb,oper=1;
    printf("Enter the number of elements in set A : ");
    scanf("%d",&na);
    printf("\nEnter the elements of set A : ");
    for(int i=0;i<na;i++)
        scanf("%d",&a[i]);

    printf("Enter the number of elements in set B : ");
    scanf("%d",&nb);
    printf("\nEnter the elements of set B : ");
    for(int i=0;i<nb;i++)
        scanf("%d",&b[i]);
    printf("Different operations are indicated by different numbers.\nEnter 1 for union\nEnter 2 for Difference");
    printf("\nEnter 3 for intersection\nEnter 4 for addition\nEnter 5 Symmetric difference\n");
    printf("Enter 6 for quit");
    while(oper !=6)
    {
        printf("\nEnter your choice for different operations : ");
        scanf("%d",&oper);
        if(oper==1)
            {
                printf("Union is :");
                aUb(a,b,na,nb);
            }
        if(oper==2)
            {
                printf("Difference is :");
                difference(a,b,na,nb);
            }
        if(oper==3)
            {
                printf("Intersection is :");
                intersection(a,b,na,nb);
            }
        if(oper==4)
            {
                printf("Addition is :");
                adding(a,b,na,nb);
            }

        if(oper==5)
            {
                printf("Symmetric difference is :");
                symmertri_diff(a,b,na,nb);
            }

    }

}
