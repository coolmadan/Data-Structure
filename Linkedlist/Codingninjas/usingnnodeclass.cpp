#include<iostream>
using namespace std;
#include"nodeclass.h"
int main()
{
    //statically
    Node n1(10);
    Node n2(20);
    cout<<n1.data<<endl;
    n1.next=&n2;
    cout<<n1.next<<endl;
    Node *head=&n1;
    cout<<(*head).data<<endl;
    cout<<head->next<<endl;
    cout<<head<<endl;
    cout<<head->next->data<<endl;
    cout<<(*head).next->data<<endl;
    //dynamically
    Node *n3=new Node(100);
    Node *n4=new Node(200);
    //yaha pe mera n3 ke pointer bngya stack memory mei jo heap wali Node ko point kr ra h ya heap wali node
    //ka address contain kre hua h(node uska type h or new btata ki wo dynamically allocate hua h heap memory mei)
    n3->next=n4;
    cout<<n3->next->data;



}