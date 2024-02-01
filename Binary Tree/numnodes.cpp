#include"levelwiseinputoutput.h"
using namespace std;
int countnodes(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return 0;
    return 1+ countnodes(root->left)+countnodes(root->right);
}
int main()
{
    BinaryTreeNode<int>*root=levelWiseInput();
    levelwiseprint(root);
    cout<<"Total number of nodes in a tree "<<countnodes(root);
}