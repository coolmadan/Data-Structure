#include"levelwiseinputoutput.h"
int heightofTree(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return 0 ;
    int smallans1=heightofTree(root->left);
    int smallans2=heightofTree(root->right);
    int ans=max(smallans1,smallans2);
    return 1+ans;
}
bool isBalanced(BinaryTreeNode<int>*root)
{
 /*   if(root==NULL)
    return 1;
    int hL=heightofTree(root->left);
    int hR=heightofTree(root->right);
    if(hL-hR<=1)
    return 1;
    bool smallans1=isBalanced(root->left);
    bool smallans2=isBalanced(root->right);
    if(smallans1==1&&smallans2==1)
    return 1;
    return 0;*/
    if(root==NULL)
    return 0;
    int leftheight=heightofTree(root->left);
    int rightheight=heightofTree(root->right);
    bool ans=0;
    if(leftheight-rightheight==1||leftheight-rightheight==0)
    {   ans=1;
    return ans;
    }
    bool smallans1=isBalanced(root->left);
    bool smallans2=isBalanced(root->right);
    if(smallans1==1&&smallans2==1)
    return 1;
    return 0;

}
int main()
{
    BinaryTreeNode<int>*root=levelWiseInput();
    cout<<isBalanced(root);
}