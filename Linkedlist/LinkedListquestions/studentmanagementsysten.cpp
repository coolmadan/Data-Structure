#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int Roll;
    string Name;
    string Sub1;
    string Sub2;
    string Sub3;
    string Sub4;
    string Sub5;
    struct Node *next;
}*Head;
void Insert_record(int roll,string name,string sub1,string sub2,string sub3,string sub4,string sub5)
{
    Head=new Node;
    Head->Roll=roll;
    Head->Name=name;
    Head->Sub1=sub1;
    Head->Sub2=sub2;
    Head->Sub3=sub3;
    Head->Sub4=sub4;
    Head->Sub5=sub5;
    Head->next=NULL;
    for(int i=1;i<5;i++)
    {
        struct Node*t;
        t= new Node;
        t->Roll
    }
}
int main()
{ string Name;
int Roll;
    string sub1,sub2,sub3,sub4,sub5;
    cout<<"Enter Name of Student\n";
    cin>>Name;
    cout<<"Enter Roll Number of Student\n";
    cin>>Roll;
    cout<<"Enter Subject 1 of Student\n";
    cin>>sub1;
    cout<<"Enter Subject 2 of Student\n";
    cin>>sub2;
    cout<<"Enter Subject 3 of Student\n";
    cin>>sub3;
    cout<<"Enter Subject 4 of Student\n";
    cin>>sub4;
    cout<<"Enter Subject 5 of Student\n";
    cin>>sub5;
    Insert_record(Roll,Name,sub1,sub2,sub3,sub4,sub5);
}