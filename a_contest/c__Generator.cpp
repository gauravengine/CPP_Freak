#include <bits/stdc++.h>
using namespace std;
int main(){
	int seed;
	cin>>seed;
	cout<<1<<" "<<3<<endl;
	srand(seed);
	cout<<rand()%3<<" "<<rand()%3<<" "<<rand()%3<<endl;
	return 0;
}