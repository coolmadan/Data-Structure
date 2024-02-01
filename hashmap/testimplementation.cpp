#include"Implementingownhashmap.h"
int main()
{
    ourMap<int> map;
   // string key="";
    for(int i=0;i<10;i++)
    {
        char c= '0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);

    }
    cout<<"size of map : "<<map.size()<<endl;
    cout<<"abc2 getvalue : "<<map.getvalue("abc2")<<endl;
    map.remove("abc2");
   // string str="abc2";
    //cout<<map.getvalue("abc2")<<endl;
    cout<<"size of map : "<<map.size()<<endl;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key+=c;
        cout<<key<<" : "<<map.getvalue(key)<<endl;
    }
    cout<<"size of map : "<<map.size();
    return 0;
}