#include<iostream>
using namespace std;

int main(){
	int seed;
	cin>>seed;
	srand(seed);
	cout<<1<<endl;
	cout<<rand()+100000000<<endl;
}