/*
Nth Root of a Number using Binary Search

Problem Statement: Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

Examples
Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.
Input : N = 4, M = 69
Output: -1
Explanation : The 4th root of 69 does not exist. So, the answer is -1.
*/

#include<iostream>
using namespace std;

long long power(int n,int m){
    long long res=1;
    for(int i=1;i<=m;i++)
        res=res*n;
    return res;
}

int brute(int n,int m){
    for(int i=1;i<=m;i++){
        if(power(i,n)==m)
            return i;
        else if(power(i,n)>m)
            break;
    }
    return -1;
}

int optimal(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid=(low+high)/2;
        if(power(mid,n)==m)
            return mid;
        else if(power(mid,n)<m)
            low=mid+1;
        else    
            high=mid-1;
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    cout<<brute(n,m)<<endl;
    cout<<optimal(n,m)<<endl;
}
