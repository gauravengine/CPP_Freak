#include<iostream>
using namespace std;

struct node
{ int data;
	node *next;
	
};
int main()
{
	node n1;
	n1.data=1;
	n1.next=NULL;
	cout<<n1.next;
 node *n2=new node;
 n2->data=2;
 n2->next=NULL;
 cout<<n2->next->next;


}