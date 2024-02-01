#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> removeDuplicates(int input[],int size)
{
    vector<int>ans;
    unordered_map<int,bool>seen;
    for(int i=0;i<size;i++)
    {
        if(seen.count(input[i])>0)
        continue;
        seen[input[i]]=true;
        ans.push_back(input[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int *input= new int[n];
    for(int i=0;i<n;i++)
    cin>>input[i];
    vector<int> output=removeDuplicates(input,n);
    for(int i=0;i<output.size();i++)
    cout<<output[i];
}