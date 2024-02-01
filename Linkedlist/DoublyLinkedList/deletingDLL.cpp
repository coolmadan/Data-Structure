#include<iostream>
using namespace std;
struct DoublyNode
{
    struct DoublyNode *prev;
    int data;
    struct DoublyNode *next;
}*First;
void create(int A[],int n)
{   
    struct DoublyNode*t,*last;
    First=new DoublyNode;
    First->data=A[0];
    First->next=First->prev=NULL;
    last=First;

    for(int i=1;i<n;i++)
    {
        t= new DoublyNode;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;

    }
}

void del(struct DoublyNode*p,int pos,int length)
{
    if(pos>0&&pos<=length) 
    {
        if(pos==1)
        {       
            First=First->next;
            First->prev=NULL;
            delete p;
        }
        else if(pos==length)
        {       struct DoublyNode*temp;
            for(int i=0;i<length-2;i++)
            {
                p=p->next;
            }
            temp=p->next;
            delete temp;
            p->next=NULL;
            
            

        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {   
                p=p->next;
            }
            p->prev->next=p->next;
            p->next->prev=p->prev;
            delete p;
        }
    }
    else
    cout<<"Position input is wrong";

}
void display(struct DoublyNode *p)
{
    do
    {
        cout<<p->data<<" ";
        p=p->next;
    }while(p);
    cout<<endl;
}
int length(struct DoublyNode*p)
{
    int count=0;
    while(p)
    {   count++;
        p=p->next;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int x,len;
    cout<<"Enter position to be deleted"<<endl;
    cin>>x;
    create(A,n);
    len=length(First);
    
    display(First);
    del(First,x,len);
    display(First);
    return 0;

}