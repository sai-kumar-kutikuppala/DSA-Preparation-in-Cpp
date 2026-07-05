/*
Count the number of set bits

Problem Statement: Given an integer n, return the number of set bits (1s) in its binary representation.
Can you solve it in O(log n) time complexity?

Examples
Example 1:
Input: 
n = 5
Output:
 2
Explanation: 
The binary representation of 5 is 101, which has 2 set bits.

Example 2:
Input: 
n = 15
Output: 
4
Explanation: 
The binary representation of 15 is 1111, which has 4 set bits.
*/

#include<iostream>
using namespace std;

int brute(int n){
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
    return ones;
}

int better(int n){
    return __builtin_popcount(n);
}

int optimal(int n){
    int cnt=0;
    while(n!=0){
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;

    cout<<brute(n)<<endl;
    cout<<better(n)<<endl;
    cout<<optimal(n)<<endl;
}