#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
int start1=1,start1_negation=1,end1,end1_negation,start2=1,start2_negation=1,end2,end2_negation;
void bs1(int n,int start,int end);

void bs2(int n,int start,int end){
		//int start =1;
		//int end=n;
		while(start<=end){
			int mid=(start+end)/2;
			cout<<mid<<endl;
			char grader; cin>>grader;
			if(grader=='L'){
				end2=mid-1;
			}
			if(grader=='G'){
				start2=mid+1;
			}
			if(grader=='E') {
				exit(0);
			}

			if(grader=='L'){
				start2_negation=mid+1;
			}
			if(grader=='G'){
				end2_negation=mid-1;
			}
			if(grader=='E') {
				exit(0);
			}



			bs1(n,start1,end1);
		}
}
void bs1(int n,int start,int end){
	//int start =1;
	//	int end=n;
		while(start<=end){
			int mid=(start+end)/2;
			cout<<mid<<endl;
			char grader; cin>>grader;
			if(grader=='L'){
				end1=mid-1;
			}
			if(grader=='G'){
				start1=mid+1;
			}
			if(grader=='E') {
				exit(0);
			}

			if(grader=='L'){
				start1_negation=mid+1;
			}
			if(grader=='G'){
				end1_negation=mid-1;
			}
			if(grader=='E') {
				exit(0);
			}
			bs2(n,start2,end2);
		}

}



int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n;
	cin>>n;
	end1=n;
	end2=n;
	end1_negation=n;
	end2_negation=n;
	bs1(n,0,n);
	//bs2(n,0,n);

		/*
		int start =1;
		int end=n;
		while(start<end){
			int mid=(start+end)/2;
			cout<<mid;
			char grader; cin>>grader;
			if(grader=='L'){
				end=mid-1;
			}
			if(grader=='G'){
				start=mid+1;
			}
			if(grader=='E') {
				break;
			}


		} */


	


	return 0;
}