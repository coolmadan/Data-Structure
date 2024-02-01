#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node*next;
}*head;
void create(int A[],int n)
{   struct Node *last;
    head=new Node;
    head->data=A[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++){
        struct Node*p;
        p=new Node;
        p->data=A[i];
        last->next=p;
        p->next=NULL;
        last=p;
    }
}
void remove_dup(struct Node*h)
{   
    struct Node*q,*p;
    while(h)
    {
        p=h;
        q=h->next;
        while(q)
        {
            if(h->data==q->data)
            {
                p->next=q->next;
                free(q);
                q=p->next;
            }
            else
            {
                q=q->next;
                p=p->next;
            }
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
    cout<<endl;
}
int main()
{
    int arr[]={2,4,2,5,4};
    create(arr,5);
    display(head);
    remove_dup(head);
    display(head);
    return 0;
}