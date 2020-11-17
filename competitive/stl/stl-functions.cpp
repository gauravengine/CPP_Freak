#include<bits/stdc++.h>
using namespace std;
struct Interval{
  int st;
  int et;

};
bool compare(Interval i1,Interval i2){
  return i1.st<i2.st;
}
int main(){
 int arr[]={ 10 , 30,20,50 ,44,99,89};
  sort(arr,arr+7);
  for (int i=0;i<7;i++) {
    cout<<arr[i]<<" ";}
cout<<endl;
    cout<<binary_search(arr,arr+7,90);

/*Interval a[]={{6,4},{3,4},{4,6},{8,13}};
sort(a,a+4,compare);

for (int i=0;i<4;i++) {
  cout<<a[i].st<<" : "<<a[i].et<<" \n"; } */

}










//                              coding ninjas code
/*#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>


using namespace std;

struct Interval{
	int st;
	int et;
};

bool compare(Interval i1,Interval i2){
	return i1.st > i2.st;
}
int main(){	//Interval arr[] = {{6,4} , {3,4}, {4,6} , {8,13}};
	//sort(arr,arr+4,compare);
	int arr[] = {1,3,2,5,7,6};
	sort(arr,arr+6);
	for(int i=0;i<6;i++){
		cout<<arr[i] << " ";
	}

	cout<<endl;
	cout << binary_search(arr,arr+6,2);
	cout<<endl;

	cout<<lower_bound(arr,arr+6,3) - arr;
	cout<<endl;

	cout<<upper_bound(arr,arr+6,3) - arr;
	cout<<endl;

	cout<<endl;

	cout<<__gcd(10,6)<<endl;

	cout<<pow(2.2,5)<<endl;

	int x= 10;
	int y=12;
	swap(x,y);
	cout<<x<<endl;
	cout<<y<<endl;

	cout<<min(14,18)<<endl;
		// for(int i=0;i<4;i++){
	// 	cout << arr[i].st << " : " << arr[i].et << endl;
	// }
	return 0;
}

*/
