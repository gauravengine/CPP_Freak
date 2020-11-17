#include <iostream>
#include <cmath>
using namespace std;
 
void linrecsolver(int a,int b,int c,int term1,int term2) {
 
    float x1, x2, discriminant, realPart, imaginaryPart,a1,a2,b1,b2,c1,c2,x,y,r,t;
    discriminant = pow(b,2) - (4*a*c);
    
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        a1=b1=1;
        c1=term1*(-1);
        a2=x1;
        b2=x2;
        c2=term2*(-1);
        x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
        y = (c1*a2 - c2*a1) / (a1*b2 - a2*b1);
        cout<<"\nSolution: An="<<x<<"*("<<x1<<")^n"<<"+("<<y<<"*("<<x2<<")^n";
        
    }
    
    else if (discriminant == 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        a1=1;
        b1=0;
        c1=term1*(-1);
        a2=x1;
        b2=x1;
        c2=term2*(-1);
        x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
        y = (c1*a2 - c2*a1) / (a1*b2 - a2*b1);
        cout<<"\nSolution: An="<<x<<"*("<<x1<<")^n"<<"+("<<y<<"*n*("<<x1<<")^n";
 
    }
 
    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        r=sqrt(pow(realPart,2)+pow(imaginaryPart,2));
        t=atan(imaginaryPart/realPart);
        a1=1;
        b1=0;
        c1=term1*(-1);
        a2=r*cos(t);
        b2=r*sin(t);
        c2=term2*(-1);
        x = (b1*c2 - b2*c1) / (a1*b2 - a2*b1);
        y = (c1*a2 - c2*a1) / (a1*b2 - a2*b1);
        cout<<"Solution: An=("<<r<<")^n"<<"*("<<x<<"cos(n."<<t<<")+("<<b<<")sin(n."<<t<<"))";
    }
}
int main()
{
    int A,B,term1,term2;
    char ch;
    do{
    cout<<"To find the solution of a recurrence relation of type Fn=A.Fn-1 + B.Fn-2.\nEnter A: ";
    cin>>A;
    cout<<"Enter B: ";
    cin>>B;
    cout<<"Enter the first term of the sequence: ";
    cin>>term1;
    cout<<"Enter the second term of the sequence: ";
    cin>>term2;
    linrecsolver(1,A*(-1),B*(-1),term1,term2);
    cout<<"\nDo you want to continue?(Enter Y or y to continue)\n";
    cin>>ch;
    }while(ch=='Y'||ch=='y');
    return 0;
}

