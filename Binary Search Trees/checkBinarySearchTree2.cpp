/*
Last method was correct but the time complexity of it was to high so here we are going with another approach
by which we will try to reduce the time ocmplexity
APPROACH :
1) if root is null return true
2) create a custom class with its data members as maximum ,minimum and IsBST
3) get the maximum and minimum for each node and compare with its root data and pass forward
4) along with is the subroot is bst or not
5)now return isBST
*/
#include"binarytreeheader.h"
pair<bool,pair<int,int>> isBst(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        pair<bool,pair<int,int>>p;
        p.first=
    }
}
int main()
{
    BinaryTreeNode<int>*root= levelwiseInput();

}