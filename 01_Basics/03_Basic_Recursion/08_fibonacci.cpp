/*
Print Fibonacci Series up to Nth term

Problem Statement: Given an integer N. Print the Fibonacci series up to the Nth term.

Examples
Example 1:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing)

Example 2:
Input: 6
Output: 0 1 1 2 3 5 8
Explanation: 0 1 1 2 3 5 8 is the fibonacci series upto 6th term.(o based indexing)
*/

#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0||n==1)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int iterative(int n){
    int first=0,second=1,temp;
    while(n){
        cout<<first<<" ";
        temp=second;
        second=second+first;
        first=temp;
        n--;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<fibonacci(i)<<" ";
    }

    cout<<endl;

    iterative(n);
}