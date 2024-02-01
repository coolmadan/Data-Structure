#include<iostream>
using namespace std;
#include "nodeclass.h"
Node *takeinput()
{

}
Node * deleteNode(Node *head,int pos)
{
    Node *temp=head;
    Node *del=NULL;
    if(pos==0)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
    for(int j=0;j<pos-1&&temp!=NULL;j++)
    {
        temp=temp->next;
    }
    del=temp->next;
    temp->next=del->next;
    delete del;
    return head;
}
int main()
{

}