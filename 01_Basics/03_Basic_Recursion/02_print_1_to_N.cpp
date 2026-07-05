/*
Print 1 to N using Recursion

Problem Description: Given an integer N, write a program to print numbers from 1 to N.

Input: N = 4
Output: 1, 2, 3, 4
Explanation: All the numbers from 1 to 4 are printed.
Input: N = 1
Output: 1 
Explanation: This is the base case
*/

#include<iostream>
using namespace std;

void print(int i,int n){
    if(i>n)
        return;
    cout<<i<<" ";
    print(i+1,n);
}

void print_backtrack(int i,int n){
    if(i<=0)
        return;
    print_backtrack(i-1,n);
    cout<<i<<" ";
}

int main(){
    int n;
    cin>>n;
    print(1,n);
    cout<<endl;
    print_backtrack(n,n);
}