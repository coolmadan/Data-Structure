#include<iostream>
using namespace std;
#include"nodeclass.h"
Node * linkedlist()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1)
    {
        Node *newNode= new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=tail->next;//or tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node * insertion(Node *head ,int data, int i)
{
    Node *newNode= new Node(data);
    Node *temp=head;
    
    if(i==0)
    {
        newNode->next=head;
        head=newNode;
    }else if(temp!=NULL &&i!=0)
    {
    for(int j=0;j<i-1;j++)
    {
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    }else
    return head;
    return head;
}
int main()
{
    Node *head=linkedlist();
    print(head);
    cout<<endl;
    head=insertion(head,6,5);
    print(head);
}