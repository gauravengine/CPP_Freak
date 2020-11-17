#include <iostream>
using namespace std;
struct abcd
{
int a ; char b; char c; int d;	
};
int main(){
	int X,Y,L,M,A,B;
    X = -20 ; Y = 15; L = X | Y ; M = X & Y ; A = X || Y ; B = X && Y ;
    cout<<L<<" "<<M<<" "<<A<<" "<<B;
}