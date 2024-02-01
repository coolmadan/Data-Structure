#include"levelwiseinputoutput.h"
bool findNode(BinaryTreeNode<int>*root,int key)
{
    if(root==NULL)
    return 0;
    if(root->data==key)
    return 1;
    else
    {
        bool smallans1=findNode(root->left,key);
        bool smallans2=findNode(root->right,key);
        if(smallans1==1||smallans2==1)
        return 1;
    }
    return 0;
}
bool findNode2(BinaryTreeNode<int>*root,int key)
{
   
    int ans=0;
    queue<BinaryTreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        BinaryTreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        if(front->data==key)
        ans=1;
      //  else if(front->)
    }
}
int main()
{
    int key;
    BinaryTreeNode<int>*root=levelWiseInput();
    cout<<"Enter key : ";
    cin>>key;
    cout<<findNode(root,key);
    

}