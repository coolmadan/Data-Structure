#include<iostream>
using namespace std;
struct DoublyNode
{
    struct DoublyNode *prev;
    int data;
    struct DoublyNode *next;
}*first;

void create(int A[],int n)
{
    struct DoublyNode*last, *p;
    first=new DoublyNode;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        p=new DoublyNode;
        p->data=A[i];
        p->next=last->next;
        p->prev=last;
        last->next=p;
        last=p;
        
    }

}
void display(struct DoublyNode*p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    int A[]={2,3,4,5,6,7,8};
    create(A,7);
    display(first);
    return 0;
}