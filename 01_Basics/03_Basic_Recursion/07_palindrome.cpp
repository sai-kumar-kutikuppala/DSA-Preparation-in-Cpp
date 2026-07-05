/*
Check if the given String is Palindrome or not

Problem Statement: Given a string, check if the string is palindrome or not. A string is said to be palindrome if the reverse of the string is the same as the string.

Examples
Example 1:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.

Example 2:
Input: Str = “TAKE U FORWARD”
Output: Not Palindrome
Explanation: String when reversed is not the same as string.
*/

#include<iostream>
using namespace std;

bool palindrome(string s,int l,int u){
    if(l>u)
        return true;
    if(s[l]!=s[u])
        return false;
    return palindrome(s,l+1,u-1);
}

int main(){
    int T;
    string s;
    cin>>T;
    cin.ignore();

    for(int i=0;i<T;i++){
        getline(cin,s);
        cout<<palindrome(s,0,s.size()-1)<<" ";
    }
}
