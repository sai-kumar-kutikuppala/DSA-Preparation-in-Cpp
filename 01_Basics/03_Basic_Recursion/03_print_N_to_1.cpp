/*
Print N to 1 using Recursion

Problem Description: Given an integer N, write a program to print numbers from N to 1.

Examples
Input: N = 4
Output: 4, 3, 2, 1
Explanation: All the numbers from 4 to 1 are printed.
Input: N = 1
Output: 1 
Explanation: This is the base case.
*/

#include<iostream>
using namespace std;

void print(int i,int n){
    if(i<=0)
        return;
    cout<<i<<" ";
    print(i-1,n);
}

void print_backtrack(int i,int n){
    if(i>n)
        return;
    print_backtrack(i+1,n);
    cout<<i<<" ";

}
int main(){
    int n;
    cin>>n;
    print(n,n);
    cout<<endl;
    print_backtrack(1,n);
}