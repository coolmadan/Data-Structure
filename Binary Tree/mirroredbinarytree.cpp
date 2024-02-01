#include"levelwiseinputoutput.h"
void mirroring(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return;
    if(root->left!=NULL&&root->right!=NULL)
    {
        BinaryTreeNode<int>*temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirroring(root->left);
        mirroring(root->right);
    }
}

int main()
{
    BinaryTreeNode<int>*root=levelWiseInput();
    levelwiseprint(root);
    mirroring(root);
    levelwiseprint(root);
    delete root;
    
}