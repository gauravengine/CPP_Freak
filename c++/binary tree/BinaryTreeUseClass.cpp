#include<iostream>
#include"BinaryTreeNode.h"
#include<queue>
using namespace std;

BinaryTreeNode<int> * buildTreeHelper(int* in,int* pre,int inS,int inE,int preS,int preE){






} 



BinaryTreeNode<int> * buildTree(int* in,int* pre,int size){
	return buildTreeHelper(in ,pre,0,size-1,0,size-1);
} 

void inorder(BinaryTreeNode<int> * root){

	if(root==NULL){
		return ;
	}
	inorder(root->left);   
	cout<<root->data<<" ";
	inorder(root->right);
// return;

}
void preorder(BinaryTreeNode<int> *root){
	if(root== NULL){
		return;
	}
	if(root != NULL){
	cout<<root->data<<" ";
}
preorder(root->left);
preorder(root->right);

}

void postoreder(BinaryTreeNode<int> *root){
	if(root ==NULL){
		return;
	}
	postoreder(root->left);
	postoreder(root->right);
	cout<<root->data<<" ";



}

int numnodes(BinaryTreeNode<int> * root){
if(root==NULL){
	return 0;
}
   return (1 + numnodes(root->left) +numnodes(root->right) );  


}

BinaryTreeNode<int> * takeInputLevelWise(){
 int rootdata;
cout<<"enter  root data \n"; cin>>rootdata;
if(rootdata == -1 ) return NULL;

BinaryTreeNode<int> *root= new BinaryTreeNode<int>(rootdata);

queue<BinaryTreeNode<int>*> pendingNodes;
pendingNodes.push(root);
while(pendingNodes.size() != 0){

BinaryTreeNode<int> * front= pendingNodes.front();
pendingNodes.pop();
cout<<"enter left child of "<<front->data<<endl;
int leftChilddata;
cin>>leftChilddata;
if(leftChilddata != -1){
	BinaryTreeNode<int> *leftChild= new BinaryTreeNode<int> (leftChilddata);
	front->left=leftChild;
	pendingNodes.push(leftChild);
}

cout<<"enter right child of "<<front->data<<endl;
int rightChilddata;
cin>>rightChilddata;
if(rightChilddata != -1){
	BinaryTreeNode<int> *rightChild= new BinaryTreeNode<int> (rightChilddata);
	front->right=rightChild;
	pendingNodes.push(rightChild);

}


}


	return root;
}


BinaryTreeNode<int> * takeInput(){
int rootdata;
cout<<"enter data \n"; cin>>rootdata;
if(rootdata == -1 ) return NULL;

BinaryTreeNode<int> *root= new BinaryTreeNode<int>(rootdata);
BinaryTreeNode<int> *leftChild= takeInput();
BinaryTreeNode<int> *rightChild=takeInput();
root->left=leftChild;
root->right=rightChild;

return root;

}



void printTree(BinaryTreeNode<int>* root){
	if(root==NULL) return ;
	cout<<root->data<<" : ";
	if(root->left != NULL)
	cout<<"L "<<(root->left->data);

	if(root->right != NULL)
	cout<<" R "<<(root->right->data);

	cout<< endl;

	printTree(root->left);
	printTree(root->right);

}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){

	


	/* BinaryTreeNode<int> *root=new BinaryTreeNode<int>(1);
	BinaryTreeNode<int> *node1=new BinaryTreeNode<int>(2);
	BinaryTreeNode<int> *node2=new BinaryTreeNode<int>(3);
	 root->left=node1;
	 root->right=node2; */
	
	BinaryTreeNode<int>* root=takeInputLevelWise();
	 printTree(root);
	 
	cout<<"num of nodes "<<numnodes(root)<<" "<<endl; // NOT working ;( worked ! delete pehle kar dia tha XD
	postoreder(root);
	 delete root;
	 return 0;
}