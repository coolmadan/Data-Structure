#include<iostream>
using namespace std;
struct Node 
{
    int data;
    struct Node *next;
}*head;
void create(int A[],int n)
{   struct Node*last;
    head=new Node;
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        struct Node*p;
        p=new Node;
        p->data=A[i];
        last->next=p;
        p->next=NULL;
        last=p;
    }
}
void sort(struct Node*h)
{   if(h==NULL)
    return  ;
    struct Node*q;
    
    int temp;
    while(h)
    {   q=h->next;
        while(q)
        {
            if(h->data>q->data)
            {
                temp=h->data;
                h->data=q->data;
                q->data=temp;

            }
            q=q->next;
        }
        h=h->next;
    }
}
void display(struct Node*p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
 int arr[]={5,2,9,1,0};
 create(arr,5);
 sort(head);
 display(head);
 return 0;
}