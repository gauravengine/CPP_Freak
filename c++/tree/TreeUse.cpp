#include<iostream>
#include "TreeNode.h"
#include<queue>
using namespace std;
TreeNode<int> * takeInputLevel(){
	cout<<"enter root"<<endl;
	int data; cin>>data;
	TreeNode<int> * root= new TreeNode<int> (data);
	queue<TreeNode<int>* > q;
	q.push(root);
	while(q.size() != 0){
		TreeNode<int> * front=q.front();
		q.pop();
		cout<<"enter the number of children of "<<front->data<<"\n";
		int numchild; cin>>numchild;
		for(int i=0;i<numchild;i++){
			cout<<"enter "<<i+1<<" child "<<" of "<<front->data<<" ";
			int child_data; cin>>child_data;
			TreeNode<int> * child=new TreeNode<int> (child_data);
			front->children.push_back(child);
			q.push(child);


		}
	}


	return root;
}


int numnodes(TreeNode<int> * root){
	int ans=1;
	for(int i=0;i<root->children.size();i++){
		ans += numnodes(root->children[i]);
	}
 return ans;

}

TreeNode<int> * takeInput(){
	int data;
	cout<<"enter data"<<endl;
	cin>> data;
	TreeNode<int> * root= new TreeNode<int>(data);
	cout<<"enter number of children of "<<data<<endl;
	int rootChild; cin>> rootChild;
	for(int i=0; i< rootChild;i++){
		TreeNode<int> * childNode = takeInput();
		root->children.push_back(childNode);
	}


return root;
}

void printNode( TreeNode<int> * root){
if(root == NULL) { // its not base case tho
return;
}

cout<<root->data<<" : ";
for(unsigned int i=0;i<root->children.size();i++){
	cout<<(root->children[i]->data)<<" , ";
}
cout<<endl;
for(unsigned int i=0;i<root->children.size();i++){
	printNode(root->children[i]);
}
//return;  even if it is not used its working fine; GREAT
}
void printatlevelK(TreeNode<int> * root,int k){
	if(k==0){
		cout<<root->data<<" ";
	}
	for(int i=0;i<root->children.size();i++){

		printatlevelK(root->children[i],k-1);

	}



}

int main(){
	/* TreeNode<int>* root=new TreeNode<int>(1);
	//root-> data=1;
	//cout<<root->data;
	TreeNode<int>* node1=new TreeNode<int>(2);
	TreeNode<int>* node2=new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2); */

	TreeNode<int > * root = takeInputLevel();
	printNode(root);
	cout<<"\n"<<numnodes(root)<<"\n";
	int k; cin>>k;
	printatlevelK(root,k);
	return 0; 
}