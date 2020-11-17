#include<iostream>
#include<math.h>
using namespace std;

class node{
public: int data;
node * next;
node( int data){
this->data=data;  next=NULL;
}
}*head;

int main(){
head=new node(10);
cout<<head->data;



}
