/*
Sum of first N Natural Numbers

Problem Statement: Given a number ‘N’, find out the sum of the first N natural numbers .

Examples
Input: N=5
Output: 15
Explanation: 1+2+3+4+5=15

Input: N=6
Output: 21
Explanation: 1+2+3+4+5+6=15
*/

#include<iostream>
using namespace std;

int sum(int n){
    if(n==0)
        return 0;
    return n+sum(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<sum(n);
}