#include<bits/stdc++.h>
using namespace std;
string extractUniqueCharacters(string s)
{
    string ans="";
    unordered_map<char,int>ourmap;
    for(int i=0;s[i]!='\0';i++)
    {   if(ourmap.count(s[i])==0)
        ans+=s[i];
        ourmap[s[i]]++;
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<extractUniqueCharacters(s);
}