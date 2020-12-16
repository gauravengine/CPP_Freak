// Created by Yadav_Gaurav
#include <bits/stdc++.h>
#include<unordered_set>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define mod 1000000007

using namespace std;
using ll = long long;

unordered_set<int>* dfs(vector<int > * edges , unordered_set<int>* visited , int n , int start ){  // since visited is pointer i don think pass by reference is needed anyway we will see
	visited->insert(start);
	// i have to make all the set of vertices connected to start
	unordered_set<int>* output= new unordered_set<int>;
	output->insert(start);
	vector<int>::iterator  it= edges[start].begin();
	while(it != edges[start].end()){
		if(visited->count(*it) == 0){  // not visited
			// call dfs again
			unordered_set<int>* temp;
			//output->insert( dfs(edges,visited,n,*it) ); // but this will return unoredered set
			temp= dfs(edges,visited,n,*it);
			// now insert elements of temp in output ;-)
			for(unordered_set<int>::iterator itr= temp->begin();itr!= temp->end();itr++) output->insert(*itr);
			it++;
		}
		else{
			it++;
		}
	}
	return output;

}

unordered_set< unordered_set<int>* >* getComponents(vector<int > * edges , int n){
	unordered_set<int>* visited = new unordered_set<int>;
	unordered_set< unordered_set<int>* >* output= new unordered_set< unordered_set<int>* >();
	for(int i=1;i<=n;i++){
		if(visited->count(i)==0){
			//visited->push_back(i); will do in dfs
 			unordered_set<int>* temp = new unordered_set<int>;
			temp = dfs(edges, visited, n, i);
			output->insert(temp);
		}
	}

	return output;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        // int* p =new int[n+1];
        // int* q= new int[n+1];
        // for(int i=1; i<=n; i++) {
        // 	cin>>p[i];
        // }
        // for(int i=1; i<=n; i++) {
        // 	cin>>q[i];
        // }
    	
        unordered_set< unordered_set<int>*>* components = new unordered_set<unordered_set<int>*>;
        vector<int>* edges = new  vector<int>[n+1];
        
        for(int i=1;i<=e;i++){
        	int x,y; cin>>x>>y;
        	edges[x].push_back(y);
        	edges[y].push_back(x);
        }

    	components = getComponents(edges,n);
    	// unordered_set< unordered_set<int>*>::iterator it = components->begin();
    	// // make sets of element at positions of *it set
    	// bool flag= false;
    	// while(it != components->end()){
    	// 	unordered_set<int>* component= *it;
    	// 	// unordered_set<int>::iterator it2= (*it)->begin();  can be used but confusing
    	// 	unordered_set<int>::iterator it2= component->begin();
    	// 	set<int> p_indices;
    	// 	set<int> q_indices;
    	// 	while(it2!= component->end()){
    	// 		p_indices.insert(p[*it2]);
    	// 		q_indices.insert(q[*it2]);
    	// 		it2++;
    	// 	}
    	// 	if(p==q) {flag= true; break;}
    	// 	it++;
    	// }

    	// if(flag ) cout<<"YES";
    	// else cout<<"NO";
 	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	while (it != components->end()) {
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while (it2 != component->end()) {
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;
		delete component;
		it++;
	}
	delete components;
	delete edges;



        cout<<'\n';
    }
    return 0;
}