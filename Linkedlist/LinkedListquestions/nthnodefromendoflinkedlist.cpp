#include<iostream>
#include<strings.h>
#include<array>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*Head=NULL;
void create(int A[],int n)
{
    struct Node *last;
    Head=new Node;
    Head->data=A[0];
    Head->next=NULL;
    last=Head;

    for(int i=1;i<n;i++)
    {
        struct Node *p;
        p = new Node;
        p->data=A[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }
}
void solution(struct Node *h,int n)
{
    struct Node*p;
    int count=0;
    p=h;
   while(p)
   {
       count++;
       p=p->next;
   }
   if(count<n)
   exit(1);
   p=Head;
   for(int i=1;i<count-n+1;i++)
   {
       p=p->next;
   }
   cout<<p->data<<endl;
}
void display(struct Node *h)
{
    while(h)
    {
        cout<<h->data<<" ";
        h=h->next;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A,5);
    solution(Head,2);
    display(Head);
    return 0;
}