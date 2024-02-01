#include"levelwiseinputoutput.h"
BinaryTreeNode<int>*buildTreeHelper(int *in,int *pre,int InS,int InE,int PreS,int PreE)
{   if (InS>InE)
    return NULL;
    int rootdata=pre[PreS];//root ka data
    int rootIndex=-1;
    for(int i=InS;i<InE;i++)
    {
        if(in[i]==rootdata)
       { rootIndex=i;
       break;}
    }
    // Intialising left subtree root's indeces for recursion call
    int LInS=InS;
    int LInE=rootIndex-1;
    int LPreS=PreS+1;
    int LPreE=LInE-LInS+PreS;
    //Intialising right subtree root's indices for recursion call
    int RInS=rootIndex+1;
    int RInE=InE;
    int RPreS=LPreE+1;
    int RPreE=PreE;
    //recursive calls follow :
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
    root->left=buildTreeHelper(in,pre,LInS,LInE,LPreS,LPreE);
    root->right=buildTreeHelper(in,pre,RInS,RInE,RPreS,RPreE);
    return root;
}
BinaryTreeNode<int>* buildTree(int *in,int *pre,int size)
{
    return buildTreeHelper(in,pre,0,size-1,0,size-1);
}
int main()
{
    int size;
    cout<<"Enter size : ";
    cin>>size;
    int * in= new int[size];
    int * pre =new int[size];
    cout<<"InOrder Traversals : ";
    for(int i=0;i<size;i++)
    {
        cin>>in[i];
    }for(int i=0;i<size;i++)
    {
        cout<<in[i];
    }
    cout<<"PreOrder Traversals : ";
    for(int i=0;i<size;i++)
    cin>>pre[i];
    BinaryTreeNode<int>*root=buildTree(in,pre,size);
    levelwiseprint(root);
    delete in;
    delete pre;
    return 0;
}