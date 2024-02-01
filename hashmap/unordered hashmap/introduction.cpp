//unordered hashmap
#include<iostream>
#include<unordered_map>//including header file for unordered hashmap
#include<string>
using namespace std;
int main()
{
unordered_map<string,int> ourMap;//unordered hashmap of name ourMap whose key is of type string and value if of type integer
//has been created
//inserting in hashmap
pair<string,int>p("abc",1);
ourMap.insert(p);
ourMap["def"]=2;
cout<<ourMap.at("abc")<<endl;
cout<<ourMap["def"]<<endl;
cout<<ourMap["gih"]<<endl;//since gih is not present in our hashmap so what [] will do is they will insert gih
//in hashmap first with value 0 and then return 0
//on the other hand if ourMap.at("gih") had been used it had thrown error cuz gih is not present in our hashmap
//now lets suppose you need to find if gih is present in your hashmap or not
/*
1) You cannot be able to use .at() function because it will throw an error if it isn't present in the hashmap
2) You cannot use [] becuase it will insert gih and its corresponding value to 0 
Thus you need to do something else to figure out if the given key is present the hashmap or not
And to do so what we can do is use count() function , what it will do is provide us with the number of times
the key is present in our hashmap but since the hashmap can only contain unique keys that means a key cannot be available in hashmap for 
more than one time and this count function will either return us with 1 or 0 stating if it is present or not
*/
//checking if the key is present in hashmap or not
if(ourMap.count("gih")>0)
cout<<"The key is present";
else
cout<<"the key is not present";
//now we can also erase the key along with its value
ourMap.erase("gih");
//return the size of hashmap
cout<<ourMap.size();
}