#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size; int arr[size]; int sumeven=0,sumodd=0;
    for(int i=0;i<size;i++){
        cin>>arr[i];
        }
    for(int i=0;i<size;i++){
        if(i%2==0 && arr[i]%2==0) {
            sumeven+=arr[i];
        }
        if(i%2!=0&&arr[i]%2 !=0) sumodd+=arr[i];
    }


    cout<<sumeven<<" "<<sumodd;
	return 0;
}
