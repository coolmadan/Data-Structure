
#include"levelwiseinputoutput.h"
class BalancedReturnType
{
    public:
    bool isBalanced;
    int height;
};
BalancedReturnType *isBalanceHelper(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        BalancedReturnType *ans=new BalancedReturnType();
        ans->height=0;
        ans->isBalanced=true;
        return ans;
    }
 //   BalancedReturnType *ans=new BalancedReturnType();
    BalancedReturnType *ans1= isBalanceHelper(root->left);
    BalancedReturnType*ans2=isBalanceHelper(root->right);
    bool flag;
    if(!(ans1->isBalanced)||!(ans2->isBalanced)||abs(ans1->height-ans2->height)>1)
    flag=false;
    else
    flag=true;
    BalancedReturnType*ans=new BalancedReturnType();
    ans->isBalanced=flag;
    ans->height=max(ans1->height,ans2->height)+1;
    return ans;

}
bool isBalanced(BinaryTreeNode<int>*root)
{
    BalancedReturnType *ans= isBalanceHelper(root);
    return ans->isBalanced;
}
int main()
{
    BinaryTreeNode<int>*root=levelWiseInput();
    cout<<isBalanced(root);

}
//approach 1
/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

**********************************************************
#include <cmath>

int height(BinaryTreeNode<int> *root)
{   if(root==NULL)
       return 0;
 
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root) {
    
    if (root == NULL) 
        return 1; 
    int l=height(root->left);
	int r=height(root->right);	
   
     if ( ( abs(l- r) ==0 || abs(l-r) == 1 ) && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    
   return 0;
}
*/
//Time Complexity for approach 1 i.e. the basic approach is O(N*H)
//where n is the number of nodes and h is the height of the tree which is too high so to reduce this
//problem we went with our second approach where we used class ans got our answer in O(N) time complexity
