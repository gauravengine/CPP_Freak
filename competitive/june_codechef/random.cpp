#include <bits/stdc++.h> 
using namespace std; 
//#define bool int 

/* Function to check if x is power of 2*/
int isPowerOfTwo (int x) 
{ 
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x&(x-1))); 
} 

/*Driver code*/
int main() 
{ 
	cout<<isPowerOfTwo(32)<<endl;
} 
