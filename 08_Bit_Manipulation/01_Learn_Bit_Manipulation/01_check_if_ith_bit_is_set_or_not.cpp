/*
Check if the i-th bit is set or not

Problem Statement: Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.

Examples
Example 1:
Input: 
n = 5, i = 0
Output: 
true
Explanation: 
Binary representation of 5 is 101. The 0-th bit from LSB is set (1).

Example 2:
Input: 
n = 10, i = 1
Output: 
true
Explanation: 
Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).
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

int convert2Decimal(string bin){
    int n = bin.size();
    int num=0,p2=1;
    for(int i=n-1;i>=0;i--){
        if(bin[i]=='1')
            num+=p2;
        p2=p2*2;
    }
    return num;
}

bool brute(int n,int i){
    string bin=conevrt2Binary(n);
    int len = bin.size();
    if(bin[len-1-i]=='1')
        return true;
    else
        return false;
}

bool optimal(int n,int i){
    if((n & (1<<i))!=0)
        return true;
    else
        return false;
}

int main(){
    int n,i;
    cin>>n>>i;

    cout<<brute(n,i)<<endl;
    cout<<optimal(n,i)<<endl;
}