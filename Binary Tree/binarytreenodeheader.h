#include<iostream>
using namespace std;
template<typename T>
class BinaryTreeNode
{
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T>*right;
    BinaryTreeNode( T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode()//a destructor which can be called using the delete word for the object who got defined by this class data type
    {
        delete left;
        delete right;
    }
};