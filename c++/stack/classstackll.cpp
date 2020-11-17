 #include<iostream>

using namespace std;

template <typename T>


class node{
  public:
T data;
  node<T> *next;
  node(T data){
    this ->data=data;
    next= NULL;
  }
};
template <typename T>

 class stack {
   node<T> * head;
   int size; //number of elements present in stack;
   public :
   stack() {
head=NULL; size=0;
   }

int getsize(){ return size;

}
bool isempty(){ return (size==0);

}
void push(T element)
{ if(head==NULL)
  {
    head= new node<T> ( element); size++;
  }
node<T> *temp= new node<T> (element);
temp->next=head;
head=temp;
size++;


}
 T pop(){
  if(head==NULL)
  {
    cout<<" stack empty"<<endl; return 0;

  }
  T ans =head->data;  node<T> *ptr=head;
  head=head->next;
delete ptr;
size--;
return ans;
}

T top(){
  if(head==NULL) {
    cout<<"stack empty"<<endl; return 0;
  }

  return head->data ;

}



 };
