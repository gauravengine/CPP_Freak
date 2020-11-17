#include<iostream>
using namespace std;
int main(){

	int *b;
	int c;
	cin>>c;
	std::vector<int> v;
	
	b=&c;
	cout<<*b;
	return 0;
}
