#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

condition1(float R[20],int len)
{
    int count=1;
    for (int i=0;i<len;i++)
    {
        if (count==1)
        {
            for (int j=i+1;j<len;j++)
            {
                if(count==1)
                {
                    for (int k=0;k<len;k++)
                    {
                        if (R[i]+R[j]==R[k])
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
        else
            break;
    }
    if (count==1)
        {
            return true;
        }
    else
        return false;
}

condition2(float R[20],int len)
{
    int count=0;
    for (int i=0;i<len;i++)
    {
        if(R[i]==0)
            count=1;
    }
    if (count==1)
        {
            return true;
        }
    else
        return false;

}

condition3(float R[20],int len)
{
    int count=0;
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
            {
                if (R[i]+R[j]==0)
                {
                    count=1;
                    break;
                }
            }
    }
    if (count==1)
        {
            return true;
        }
    else
        return false;
}

condition4(float R[20],int len)
{
    int count=1;
    for (int i=0;i<len;i++)
    {
        for (int j=i+1;j<len;j++)
        {
            for (int k=j+1;k<len;k++)
            {
                if(R[i]+R[j]+R[k]==R[i]+R[j]+R[k])
                    continue;
                else
                    count=0;
            }
        }
    }
    if (count==1)
        {
            return true;
        }
    else
        return false;

}

condition5(float R[20],int len)
{
    int count=1;
    for (int i=0;i<len;i++)
    {
        for (int j=i+1;j<len;j++)
        {
           if((R[i]+R[j]==R[j]+R[i]))
                    continue;
                else
                    count=0;
        }
    }
    if (count==1)
        {
            return true;
        }
    else
        return false;

}

int main()
{
    float R[30];
    int len;
    printf("Enter the number of elements in a set ");
    scanf("%d",&len);
    printf("Enter the elements of set :\n");
    for (int i=0;i<len;i++)
        scanf("%f",&R[i]);
    bool prop1,prop2,prop3,prop4,prop5;
    prop1=condition1(R,len);
    prop2=condition2(R,len);
    prop3=condition3(R,len);
    prop4=condition4(R,len);
    prop5=condition5(R,len);

    if (prop1==true && prop2==true && prop3==true && prop4==true && prop5==true)
        printf("Yes,this is a ring");
    else
        printf("This is not a ring");

}
