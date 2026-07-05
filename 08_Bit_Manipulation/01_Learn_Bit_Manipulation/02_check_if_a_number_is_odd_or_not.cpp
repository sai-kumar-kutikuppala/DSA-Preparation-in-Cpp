/*
Check if a number is odd or not

Problem Statement: Given a non-negative integer n, determine whether it is odd. Return true if the number is odd, otherwise return false. A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).

Examples
Example 1:
Input:
 n = 7
Output:
 true
Explanation:
 7 is not divisible by 2. Hence, it is odd.

Example 2:
Input:
 n = 10
Output:
 false
Explanation:
 10 is divisible by 2. Hence, it is not odd.
*/

#include<iostream>
#include<algorithm>
using namespace std;

string conevrt2Binary(int n){
    string bin;
    while(n!=0){
        if(n%2==1)
            bin+="1";
        else
            bin+="0";
        n=n/2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

bool brute(int n){
    string bin = conevrt2Binary(n);
    int len = bin.size();
    if(bin[len-1]=='1')
        return true;
    return false;
}

bool optimal(int n){
    if((n & 1)==1)
        return true;
    return false;
}

int main(){
    int n;
    cin>>n;

    cout<<brute(n)<<endl;
    cout<<optimal(n)<<endl;
}