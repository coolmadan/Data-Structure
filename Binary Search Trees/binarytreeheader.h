#include<iostream>
#include<queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
    public :
    T data;
    BinaryTreeNode<T> * left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
BinaryTreeNode<int> * levelwiseInput()
{
    cout<<"Enter root's data";
    int rootData;
    cin>>rootData;
if(rootData==-1)
{
    BinaryTreeNode<int>*root= new BinaryTreeNode<int>(rootData);
    return root;
}
    BinaryTreeNode<int>*root= new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;//aisi queue jiske elements BinaryTreeNode<int> * pointer type ke h
//(BinaryTreeNode<int>* ka mtlb ki ek pointer jo aisi binaryTreeNode ko point krega jisme sirf int type ka data hoga)
pendingNodes.push(root);
while(pendingNodes.size()!=0)
{
    BinaryTreeNode<int>*front=pendingNodes.front();
    pendingNodes.pop();
    
        int leftData;
        cout<<"Enter left child data for "<<front->data<<": ";
        cin>>leftData;
        if(leftData!=-1)
        {  BinaryTreeNode<int>*leftchild=new BinaryTreeNode<int>(leftData);
        front->left=leftchild;
        pendingNodes.push(leftchild);
        }
        int rightdata;
        cout<<"Enter right child data for "<<front->data<<" : ";
        cin>>rightdata;
        if(rightdata!=-1)
        {
            BinaryTreeNode<int>*rightchild=new BinaryTreeNode<int>(rightdata);
            front->right=rightchild;
            pendingNodes.push(rightchild);
        }
     
   
    }
return root;
}
void printlevelwise(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return;
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<"L : "<<front->left->data;
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL)
        {
            cout<<" R : "<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
