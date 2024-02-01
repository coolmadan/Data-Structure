#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*Head;
void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct Node *h)
{
    do{ printf("%d ",h->data);
    h=h->next;
    }while(h!=Head);
    printf("\n");
    
}
void Rdisplay(struct Node*h)
{
    static int flag=0;
    if(h!=Head||flag==0)
    {flag=1;
    cout<<h->data<<" ";
    Rdisplay(h->next);
    }
}

int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    display(Head);
    Rdisplay(Head);
    return 0;

}