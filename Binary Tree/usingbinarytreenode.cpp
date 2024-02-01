#include<iostream>
#include<queue>
#include"binaryTreeNodeheader.h"
using namespace std;
BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter Data : ";
    cin>>rootData;
    if(rootData==-1)
    return NULL;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftchild=takeInput();
    BinaryTreeNode<int>*rightchild=takeInput();
    root->left=leftchild;
    root->right=rightchild;
    return root;
}
BinaryTreeNode<int>*levelwiseInput()
{
    int rootData;
    cout<<"Enter root Data : ";
    cin>>rootData;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingnodes.front();
        pendingnodes.pop();
      
        int leftChildData;
        cout<<"Enter leftchild for "<<front->data<<" : ";
        cin>>leftChildData;
        if(leftChildData!=-1)
        {
            BinaryTreeNode<int>*child= new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingnodes.push(child);
        }
        int rightchildData;
        cout<<"Enter right child for "<<front->data<<" : ";
        cin>>rightchildData;
        if(rightchildData!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightchildData);
            front->right=child;
            pendingnodes.push(child);
        }
    }
    return root;

}
void printLevelwise(BinaryTreeNode<int>*root)
{
//    cout<<root->data<<" : ";
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
        cout<<"L : "<<front->left->data<<" , ";
        pendingNodes.push(front->left);
        }
        if(front->right!=NULL)
        {
        cout<<"R : "<<front->right->data;
        
        pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
void print(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    return;//this is a base case which is necessary in binary tree which was not necessary in generic tree
    //because in generic tree we used a for loop to access each children of each node so we can't iterate more than the size of children for each node
    //but in this binary tree case we know we have only two child or subtrees i.e. left and right
    //so if we don't use base case and call recursion on this than the call will go again and again to the left of every node
    //and won't return when there is no left node (or NULL) just will recursively iterate through the garbage values.
    cout<<root->data<<" : ";
    if(root->left!=NULL)
   { cout<<"L "<<root->left->data;
 //   print(root->left);
   }
   if(root->right!=NULL)
   {
    cout<<"R "<<root->right->data;
 //   print(root->right);
       }
       cout<<endl;
       print(root->left);
       print(root->right);
   
}
int main()
{
   // BinaryTreeNode<int>*root=new BinaryTreeNode<int>(1);
   // BinaryTreeNode<int>*left=new BinaryTreeNode<int>(2);
   // BinaryTreeNode<int>*right=new BinaryTreeNode<int>(3);
   // root->left=left;
   BinaryTreeNode<int>*root=levelwiseInput();

  //  root->right=right;
  //  print(root);
  printLevelwise(root);
    delete root;

}