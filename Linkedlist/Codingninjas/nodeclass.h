#include<iostream>
using namespace std;
class Node
{   public:
    int data;
    Node * next;
    Node(int data)
    {
        this->data=data;//yaha pe this isliye likha kyunki data data dono same variable h to unhe compiler ko differentitate krane k liye

        next=NULL;//or yaha pe this isliye nahi likha kyunki hme next mei kuch entry daalni hi ni h
    }
};