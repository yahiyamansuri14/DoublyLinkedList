#include <iostream>
using namespace std;
struct Node{
    Node *prev;
    int data;
    Node *next;
}*first=NULL;
 void create(int a[],int size){
    Node *t,*last;
    first=new Node;
    first->data=a[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<size;i++){
        t=new Node;
        t->data=a[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
 }
 void print(Node *temp){
    while(temp){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
 }
  int length(Node *temp){
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
 }
 void insert(Node *p,int index,int x){
    Node *t;
    //check if index is valid or not
    if(index<0 || index>length(p)){
        return;
    }
    if(index==0){
        t=new Node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
    
    
 }
int main()
{
   int a[]={1,2,3,4,5,6,7,8,9,10};
   int size=sizeof(a)/sizeof(a[0]);
   create(a,size);
   insert(first,2,25);
   print(first);
   return 0;
}
