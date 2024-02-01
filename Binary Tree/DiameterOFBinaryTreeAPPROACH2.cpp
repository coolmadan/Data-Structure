//To get a more efficient output we need to reduce the time complexity of O(N*H) to O(N)
//we 
//first of all we need to decrease the complexity right?
/*So what we will do is instead of calling th height again and again we will just call for diameter and at the same time we will try to get the height as well 
as the diameter what this will do is ,by this way we don't need to get height again when we want our diameter we are just calling a single node and
getting both diameter and height   
THIS WAY OUR COMPLEXITY REDUCES FROM O(N*H) TO O(N) as we are only going to each node for a single time and doing constant amount of work
TIME COMPLEXITY =O(N*K)
where k is a constant
thus TIME COMPLEXITY= O(N)*/
#include"levelwiseinputoutput.h"
pair<int,int> heightDiameter(BinaryTreeNode<int>*root)
{
    //Base Condition
    if(root==NULL)
    {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    //Hypothesis
    pair<int,int> leftans=heightDiameter(root->left);
    pair<int,int>rightans=heightDiameter(root->right);
    //Mathematical Calculation
    int leftheight=leftans.first;
    int leftdiameter=leftans.second;
    int rightheight=rightans.first;
    int rightdiameter=rightans.second;
    int height=1+max(leftheight,rightheight);
    int diameter=max(leftheight+rightheight,max(leftdiameter,rightdiameter));
    pair<int,int>ans;
    ans.first=height;
    ans.second=diameter;
    return ans;
}
int main()
{
    BinaryTreeNode<int>*root=levelWiseInput();
    cout<<heightDiameter(root).second;
  //  levelwiseprint(root);
    return 0;
}