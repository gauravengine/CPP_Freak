#include<iostream>
#include<math.h>
using namespace std;

class node{
public: int data;
node * next;
node( int data){
this->data=data;  next=NULL;
}
}*head=NULL;

void insertbeg(int element){
node *temp; temp=new node(element);
//if(head==NULL){ head= new node(element);



  //else {temp=new node(element);
  temp->next=head;
  head=temp;}


void display(){
  while(head!=NULL){ cout<<head->data; head=head->next;}
}


int main()
{
int n;
cin>>n; //int i=0;
//int bin=0;
int dec=n;
while ((dec/2)!=0) {
insertbeg(dec%2); //if (bin==0) {i++;}
dec=dec/2;

}

insertbeg(dec%2);
//insertbeg(dec/2);


display();
  return 0;
}
