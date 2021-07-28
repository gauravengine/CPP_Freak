#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
void updateTree(int *arr,int *tree,int start,int end,int treeNode,int id,int val){
    if(start==end){
        arr[id]=val;
        tree[treeNode]=val;
        return;
    }
    int mid=(start+end)/2;
    if(id>mid){
        updateTree(arr,tree,mid+1,end,2*treeNode+1,id,val);
    }else{
        updateTree(arr,tree,start,mid,2*treeNode,id,val);
    }

    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int query(int *arr,int *tree,int start,int end,int treeNode,int left,int right){
    //3 cases
    if(start>right || end < left) return 0;
    if(start>= left && end<=right) return tree[treeNode];
    int mid=(start+end)/2;
    int op1=query(arr,tree,start,mid,2*(treeNode),left,right);
    int op2=query(arr,tree,mid+1,end,2*treeNode+1,left,right);
    return op1+op2;
}
int main(){
    ios::sync_with_stdio(false);
    int arr[5]={1,2,3,4,5};
    int tree[10];
    
    buildTree(arr,tree,0,4,1);
    for(int i=1;i<10;i++) cout<<tree[i]<<" ";
    cout<<'\n'; 
    updateTree(arr,tree,0,4,1,2,10);
    for(int i=1;i<10;i++) cout<<tree[i]<<" ";
    //[2,4]
    int ans=query(arr,tree,0,4,1,2,4);
    cout<<ans;
}
