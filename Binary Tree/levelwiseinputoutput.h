#include"binarytreenodeheader.h"
#include<queue>
BinaryTreeNode<int>* levelWiseInput()
{
    cout<<"Root data : ";
    int rootData;
    cin>>rootData;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child for "<<front->data <<" : ";
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftchild);
            front->left=child;
            pendingNodes.push(child);

        }
        cout<<"Enter right child for "<<front->data<<" : ";
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightchild);
            front->right=child;
            pendingNodes.push(child);
        }

    }
    return root;
    
}
void levelwiseprint(BinaryTreeNode<int>*root)
{
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<" : ";
        if(front->left!=NULL)
        {
            cout<<"L "<<front->left->data<<",";
            pendingNodes.push(front->left);
        }
        if(front->right!=NULL)
        {
            cout<<"R "<<front->right->data;
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}