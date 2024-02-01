#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*Head;
void create(int A[],int n)
{
    struct Node*last,*t;
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
void display()
{   struct Node *h=Head;
    do{
        cout<<h->data<<" ";
        h=h->next;
    }while(h!=Head);

}
int length(int A[])
{  int count=0;
    struct Node*p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p=Head;
    while (p->next!=Head)
    {
        count++;
        p=p->next;
    }

    
    return count;
}
void insert(int A[],int pos,int x,int length)
{
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(Head==0)
    {   
        Head=t;
        Head->next=Head;
    }
      if(pos>=0&&pos<length){
            if(pos==0)
    {   struct Node*p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p=Head;
    while(p->next!=Head)
    {
        p=p->next;   
    }             
    t->next=p->next;
    p->next=t; 

    }
    else
    {
        struct Node*p;
        p=(struct Node*)malloc(sizeof(struct Node));
        p=Head;
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;

    }
      }
}
int main()
{   int linkedlistlength;
    int A[]={2,3,4,5,6};
    create(A,5);
    linkedlistlength=length(A);
    display();
 
    insert(A,0,10,linkedlistlength);

    cout<<endl;
    display();
    return 0;
}