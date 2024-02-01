//write a program to check if the given binary tree is a binary search tree or not.
// Approach 1 : Brute Force Approach 
/*
BRUTE FORCE APPROACH :
1)Return tree if root is null
(if there is not tree than the tree is BST)
2)Compare root's data with left's maximum because for every node present at left tree of root , the root
must bigger than it .(root->data>leftreemaximum)
3)Compare root's data with right' minimum because for every node present at the right of root, the root 
must be smaller than it.(root->data<righttree->minimum)
*/
#include"binarytreeheader.h"
#include<bits/stdc++.h>
int maximum(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

bool IsBST(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return true;
    int leftmaximum=maximum(root->left);
    int rightminimum=minimum(root->right);
    bool output=((root->data>leftmaximum)&&(root->data<=rightminimum)&&IsBST(root->left)&&IsBST(root->right));
    return output;
}
int main()
{
    BinaryTreeNode<int>*root= levelwiseInput();
    printlevelwise(root);
    cout<<IsBST(root);
    delete root;
    return 0;
}
/*
TIME COMPLEXITY : O(N*H)
*/