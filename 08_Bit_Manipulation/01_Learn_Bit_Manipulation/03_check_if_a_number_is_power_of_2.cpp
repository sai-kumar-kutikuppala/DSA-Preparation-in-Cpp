/*
Check if a number is power of 2 or not

Problem Statement: Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two if there exists an integer x such that n == 2ˣ.

Examples
Example 1:
Input: 
n = 16
Output: 
true
Explanation: 
2⁴ = 16, so 16 is a power of two.

Example 2: 
Input: 
n = 3
Output: false
Explanation: 
3 is not a power of two.
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool brute(int n){
    string bin;
    int ones=0;
    while(n!=0){
        if(n%2==1){
            bin+="1";
            ones++;
        }
        else
            bin+="0";
        n=n/2;
    }
    if(ones==1)
        return true;
    return false;
}

bool optimal(int n){
    if((n & (n-1))==0)
        return true;
    return false;
}

int main(){
    int n;
    cin>>n;

    cout<<brute(n)<<endl;
    cout<<optimal(n)<<endl;
}