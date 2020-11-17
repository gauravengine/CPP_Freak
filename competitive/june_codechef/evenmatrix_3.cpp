#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;

		if(n%2 != 0)
		{
		int* arr=new int[n*n];
		vector<int> even_numbers;
		vector<int> odd_numbers;
		for(int i=1;i<(n*n)+1;i++){
			if(i%2==0) even_numbers.push_back(i);
			else
				odd_numbers.push_back(i);
		}
		for(int i=0;i<(n*n);i+=2){
			arr[i]=odd_numbers.back();
			odd_numbers.pop_back();
			arr[i+1]=even_numbers.back();
			even_numbers.pop_back();
		}
		for(int i=0;i<(n*n);i+=n){
			for(int j=i;j<i+n;j++){
				cout<<arr[j]<<" ";
			}
			cout<<endl;
		}
		delete[] arr;
		}

		else{	
				//cout<<"here";

				int square=n*n;
				int**arr = new int*[n];
				for(int i=0;i<n;i++){
					arr[i] =new int[n];
					}
				vector<int> even_numbers;
				vector<int> odd_numbers;
				for(int i=1;i<square+1;i++){
					if(i%2==0) even_numbers.push_back(i);
					else
						odd_numbers.push_back(i);
				}
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if((i+j)%2==0){ //fill odd
 							arr[i][j]=odd_numbers.back();
 							odd_numbers.pop_back();
						}
						else{
							arr[i][j]=even_numbers.back();
							even_numbers.pop_back();
						}
					}
				}
				// now printing and deletion
								for(int i=0;i<n;i++){
								for(int j=0;j<n;j++){
										cout<<arr[i][j]<<" ";
								}
									cout<<endl;
							}
					for(int i=0;i<n;i++){
						delete[] arr[i];
					}
					delete[] arr; 

						}

		}

return 0;
}
