 #include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
 /*// vector<int> v(5);
std::vector<int> v;
  for(int i=0;i<5;i++){
    //v[i]=i+1;
v.push_back(i+1);
  }
  vector<int>::iterator it;
  for(it=v.begin();it!=v.end();it++){
    cout<<*it<<endl;
  }
string s="gaurav";// string s1(s);
string s1(s,2,4);// start from 2 and will print next 4 characters;
cout<<s<<endl<<s1<<endl;
string s2=s.substr(1,4);
cout<<s2;
if(s1.compare(s2)!=0) cout<<"not equal"<<endl;*/

/*int arr[]={10,20,30,40,40,50,50};
map<int,int> m;
for(int i=0;i<7;i++){
  m[arr[i]]=m[arr[i]]+1;
}
map<int,int>::iterator it;
for(it=m.begin();it!=m.end();it++){
  cout<<it->first<<" : "<<it->second<<"\n";
}
cout<<endl;
m.erase(50); //deletes the specific key 50 here;
for(it=m.begin();it!=m.end();it++){
  cout<<it->first<<" : "<<it->second<<"\n";
} */
// unordered_map==

int arr[]={10,20,30,40,40,50,50};
unordered_map<int,int> m;
for(int i=0;i<7;i++){
  m[arr[i]]=m[arr[i]]+1;
}
unordered_map<int,int>::iterator it;
for(it=m.begin();it!=m.end();it++){
  cout<<it->first<<" : "<<it->second<<"\n";
}
cout<<endl;
m.erase(50); //deletes the specific key 50 here;
for(it=m.begin();it!=m.end();it++){
  cout<<it->first<<" : "<<it->second<<"\n";
}
}
/*#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<unordered_map>
using namespace std;



int main(){

	//Vector
	// vector<int> v;

	// for(int i=0;i<5;i++){
	// 	v.push_back(i+1);
	// }
	// vector<int>::iterator it;

	// for(it=v.begin();it!=v.end();it++){
	// 	cout<<*it<<endl;
	// }


	//String
	// string s = "Parikh";
	// string s1(s,2,4);
	// cout<<s<<endl;
	// cout<<s1<<endl;

	// string s2 = s.substr(2,4);
	// cout<<s2<<endl;

	// if(s1.compare(s2) == 0){
	// 	cout<<s1 <<"is equal to " << s2<<endl;
	// }else{
	// 	cout<<s1 <<"is not equal to " << s2<<endl;
	// }

	//Pair

	// pair<int,char> p;
	// p = make_pair(2,'b');
	// pair<int,char> p2(1,'a');
	// cout<<p.first << " " << p.second<<endl;
	// cout<<p2.first << " " << p2.second<<endl;


	//Set

	// set<int> s;
	// int arr[] = {1,2,3,4,5,6,5};

	// for(int i=0;i<7;i++){
	// 	s.insert(arr[i]);
	// }

	// set<int>::iterator it;

	// for(it=s.begin();it!=s.end();it++){
	// 	cout<<*it<<endl;
	// }

	// if(s.find(7) == s.end()){
	// 	cout<<"Element not found"<<endl;
	// }else{
	// 	cout<<"Element found"<<endl;
	// }


	// Map

	int arr[] = {1,2,3,4,5,6,5};
	unordered_map<int,int> m;

	for(int i=0;i<7;i++){
		m[arr[i]] = m[arr[i]]+1;
	}

	unordered_map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		cout<<it->first << " :" << it->second<<endl;
	}
	cout<<endl;
	m.erase(1);
	for(it=m.begin();it!=m.end();it++){
		cout<<it->first << " :" << it->second<<endl;
	}

	return 0;
} */
