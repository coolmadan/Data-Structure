#include"binarytreeheader.h"
bool Search(BinaryTreeNode<int>*root,int data)
{
    if(root==NULL)
    return false ;
    if(root->data==data)
    return true;
    if(data<root->data)
    {
        return Search(root->left,data);
    }
    if(data>root->data)
    return Search(root->right,data);
    return false;

}
int main()
{
    BinaryTreeNode<int>*root=levelwiseInput();
    int data;
    cout<<"Enter the data which you need to find : ";
    cin>>data;
    cout<<Search(root,data);
    return 0;
    delete root;
}