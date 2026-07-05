/*
Reverse Digits of A Number
Problem Statement: Given an integer N return the reverse of the given number.
Note: If a number has trailing zeros, then its reverse will not include them. For e.g , reverse of 10400 will be 401 instead of 00401.

Input: N = 12345
Output:54321
Explanation: The reverse of 12345 is 54321.

Input: N = 7789                
Output: 9877
Explanation: The reverse of number 7789 is 9877.
*/

#include<iostream>
using namespace std;

void reverse(int n){
    int d,num=0;
    while(n>0){
        d=n%10;
        n=n/10;
        num=num*10+d;
    }
    cout<<num<<" ";
}

int main(){
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        reverse(n);
    }
}