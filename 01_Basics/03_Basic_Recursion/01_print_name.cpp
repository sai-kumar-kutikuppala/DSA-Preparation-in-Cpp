/*
Print Name N times using Recursion

Problem Description: Given an integer N, write a program to print your name N times.

Input: N = 3
Output: Ashish Ashish Ashish 
Explanation: Name is printed 3 times.
Input: N = 1
Output: Ashish 
Explanation: Name is printed once.
*/

#include<iostream>
using namespace std;

void print_name(int n){
    if(n<=0)
        return;
    cout<<"sai"<<endl;
    print_name(n-1);
}
int main(){
    int n;
    cin>>n;
    print_name(n);
}