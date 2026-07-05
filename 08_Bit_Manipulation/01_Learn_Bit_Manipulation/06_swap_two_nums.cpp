/*
Swap two numbers

Problem Statement: Given two integers a and b, swap them in-place using only 2 variables (without using a temporary variable).

Examples
Example 1:
Input:
 a = 5, b = 10
Output:
 a = 10, b = 5

Example 2:
Input:
 a = -100, b = -200
Output:
 a = -200, b = -100
*/

#include<iostream>
using namespace std;

void optimal(int &a,int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){
    int a,b;
    cin>>a>>b;

    cout<<"a="<<a<<", b="<<b<<endl;
    optimal(a,b);
    cout<<"a="<<a<<", b="<<b<<endl;
}