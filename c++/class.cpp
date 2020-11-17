#include<iostream>
using namespace std;
class integer{
	int constant=9; int var;
public:
	integer()
	{ //constant=10;
     	var=0;
	}

void changer()
{

	constant++;
	var++; cout<<"new constant is : "<<constant<<endl;
	cout<<"new var is : "<<var<<endl;

}
}; 
int main()
{
	integer i1;
	i1.changer(); i1.changer(); i1.changer();
}

