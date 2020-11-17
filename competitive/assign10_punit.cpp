#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>

int e;

 operation(char o,float a,float b)
{
    if(o=='+')
        return (a+b);
    else
    {
        if (o=='-')
            return (a-b);
        else
        {
            if (o=='*')
                return (a*b);
            else
            {
                if(o=='/')
                    return (a/b);
                else
                    {
                        if(o=='^')
                            return pow(a,b);
                        else
                            printf("Incorrect operator");
                    }
            }
        }
    }
}

condition1(float G[30],int len ,char o)
{
    int count=1,i=0;
    for (;i<len;i++)
    {
        if(count==1)
        {
            for (int j=i+1;j<len;j++)
            {
                float num=operation (o,G[i],G[j]);
                {
                    if(count==1)
                    {
                        for(int k=0;k<len;k++)
                        {
                            if(num==G[k])
                            {
                                count=1;
                                break;
                            }
                            else
                                count=0;
                        }
                    }
                    else
                        break;
                }
            }
        }
        else
            break;
    }
    if (count==1)
        {
            printf("It is a closure\n");
            return true;
        }
    else
        return false;
}

condition2(float G[30],int len ,char o)
{
    int count=1;
    for (int i=0;i<len;i++)
    {
        for (int j=i+1;j<len;j++)
        {
            for (int k=j+1;k<len;k++)
            {
                float num1=operation(o,G[i],G[j]),num2=operation(o,G[j],G[k]);
                if (operation(o,num1,G[k])==operation(o,G[i],num2))
                    continue;
                else
                    count=0;
            }
        }
    }
    if (count==1)
        {
            printf("It is associative\n");
            return true;
        }
    else
        return false;

}

condition3(float G[30],int len ,char o)
{
    int count=0;
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if (operation(o,G[i],G[j])==G[i])
            {
                e=G[j];
                count=1;
                break;
            }
            else
                count=0;
        }
    }
    if(count==1)
        {
            printf("It is an identity\n");
            return true;
        }
    else
        return false;
}

condition4(float G[30],int len ,char o)
{
    int count=1;
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(operation(o,G[i],G[j])==operation(o,G[j],G[i]))
            {
                count=1;
                break;
            }
            else
                count=0;
        }
    }
    if(count==1)
    {
        printf("It is an inverse\n");
        return true;
    }
    else
        return false;
}

condition5(float G[30],int len,char o)
{
    int count=1;
    for(int i=0;i<len;i++)
    {
        if(count==1)
        {
            for(int j=i+1;j<len;j++)
            {
                if(operation(o,G[i],G[j])==operation(o,G[j],G[i]))
                {
                    count=1;
                    break;
                }
                else
                    count=0;
            }
        }
        else
            break;
    }
    if(count==1)
    {
        printf("It is commutative\n");
        return true;
    }
    else
        return false;
}

int main()
{
    float G[30];
    int len;
    char oper;
    printf("Enter the number of elements in a group ");
    scanf("%d",&len);
    printf("Enter the elements of groups \n");
    for (int i=0;i<len;i++)
        {
            scanf("%f",&G[i]);
        }
    printf("Enter the operator form +,-,*,/,^   \n");
    scanf("%s",&oper);
    bool prop1,prop2,prop3,prop4,prop5;
    prop1=condition1(G,len,oper);
    prop2=condition2(G,len,oper);
    prop3=condition3(G,len,oper);
    prop4=condition4(G,len,oper);
    prop5=condition5(G,len,oper);
    if(prop1==true && prop2==true && prop3==true && prop4==true && prop5==true)
        printf("Hence,It is a group");
    else
        printf("Hence,It is not a group");

}
