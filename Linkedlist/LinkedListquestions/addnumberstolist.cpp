#include<iostream>
#include"nodeclassusingtemplate.h"
using namespace std;
Node<int>* create_linkedlist()
{
    int data;
    cin>>data;
    Node <int>*head;
    Node<int>*tail;
    while(data!=-1)
    {   
        Node <int>*newNode=new Node<int>(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;

}
void print(Node <int> *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int number(Node <int>*head)
{
    int digit;
    int result=0;
    while(head!=NULL)
    {
        digit=head->data;
        result=result*10+digit;
        head=head->next;
    }
    return result;
}
Node<int> *solution(int res)
{
    Node<int>*head;
   
    while(res!=0)
    {
        int digit=res%10;
        Node<int>*newNode=new Node<int>(digit);
        if(head==NULL)
        {
            head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
        res=res/10;
    }
    return head;
    
}
Node <int>*sol(int x,Node <int>*head)
{
    int num2=number(head);
    int final=x+num2;
    Node<int>*fin=solution(final);
    return fin;

}
int main()
{
    Node<int>* head1=create_linkedlist();
    int x=number(head1);
    Node <int>*head2=create_linkedlist();
    Node<int>*fin=sol(x,head2);
    print(fin);
    
//    Node <int>*head=solution(head1,head2);
  //  print(head);
}
