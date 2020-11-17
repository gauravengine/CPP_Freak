#include<iostream>
#include<process.h>
using namespace std;
struct node
{ int data;
	node *next;
	
} *start,*temp,*newptr,*ptr,*rear;
node *createnewnode(int ); void insertlast(node*);
//void insertbeg(node* );
void display( node*);
int main()
{  int inf; start=NULL;
 char ch='y';
	
		do{cout<<"enter data";
	cin>>inf;
	newptr=createnewnode(inf);
	cout<<"now inserting in end of list ";
	insertlast(newptr);
	cout<<"wanna insert more?";
	cin>>ch;}while(ch=='y');
display(start);

}
 node *createnewnode(int a )
 {
 		ptr=new node;
 		ptr -> data=a;
 		ptr ->next=NULL;
 		return ptr;
 }
 /*void insertbeg( node *np)
 {
if (start==NULL)
	{start= np;
 }
else
{
	temp=start;
	start=np;
	np->next=temp;
} }*/
 void display(node *np)
 {
 	while(np!=NULL)
 	{
 		cout<<np->data<<"->";
 		np=np->next;
 	} cout<<"!!!";
 }
void insertlast(node *np)
{
	if(start==NULL)
	{
		start=rear=np;
	}
	else 
	{
		rear->next=np;
		rear=np;
	}
}

