#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[],int n)
{
    struct Node *last,*t;
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(int i=1;i<n;i++)
    {   t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
int length(struct Node *p)
{
    int count=0;
    while(p->next!=Head)
    {
        count++;
        p=p->next;
    }
    return count;
}
void del(struct Node*p,int pos,int limit)
{
    struct Node*q;
    if(pos>0 && pos<=limit)
    {
       for(int i=0;i<pos-2;i++)
       {
           p=p->next;
       }
       q=p->next;
       p->next=q->next;
       int x=q->data;
       free(q);
    }
}
void display(struct Node *p)
{
   cout<<p->data;
}
int main()
{   int limit;
    int A[]={2,4,6,8,3};
    create(A,5);
    limit=length(Head);
    //del(Head,3,limit);
    display(Head);
    return 0;
}