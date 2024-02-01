//Diameter of a Binary Tree is inspired from the dimater of a circle
//diameter of a circle is a difference between the two farthest point
//so keeping this definition in out mind we can say that
//diameter of a binary tree is a distance between the nodes at farthest or maximum distance.
#include"levelwiseinputoutput.h"
//Approach 1 :
//we will check get the diameter by checking three values
//the height of left subtree plus right subtree
// the diameter of left subtree only
//the diameter of right subtree only
//now we will return the maximum of these three as the resultant diameter
int height(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
int diameter(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    return 0;
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}

int main()
{
    BinaryTreeNode<int>*root=levelWiseInput();
    cout<<diameter(root);
}
//Time complexity for this code is too high i.e. O(N*H)
//where N is the number of nodes and H is the height of the tree
// it means for each node we are finding the hieght several times
//first we find the height for left subtree and rightsubtree
//then again we find the height of left subtree and right subtree for the left diameter
//then again we find the height of left and right for right diameter
