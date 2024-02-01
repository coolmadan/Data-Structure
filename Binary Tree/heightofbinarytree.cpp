#include"levelwiseinputoutput.h"
int heightOfTree(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return 0;
   // int ans=0;
    int smallans1=heightOfTree(root->left);
    int smallans2=heightOfTree(root->right);
    int ans=max(smallans1,smallans2);
    return 1+ans;
}
int main()
{
    BinaryTreeNode<int>*root=levelWiseInput();
    cout<<heightOfTree(root);
    delete root;
}