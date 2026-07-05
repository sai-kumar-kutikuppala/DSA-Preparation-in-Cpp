/*
Check if a number is Armstrong Number or not

Problem Statement:Given an integer N, return true it is an Armstrong number otherwise return false.
An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

Example 1:
Input:N = 153
Output:True
Explanation: 1^3+5^3+3^3 = 1 + 125 + 27 = 153
                                        
Example 2:
Input:N = 371                
Output: True
Explanation: 3^3+7^3+1^3 = 27 + 343 + 1 = 371
*/

#include<iostream>
#include<cmath>
using namespace std;

int count_digits(int n){
    int cnt=0;
    while(n>0){
        n=n/10;
        cnt++;
    }
    return cnt;
}

void armstrong(int n){
    int sum=0,d,temp=n;
    int size=count_digits(n);
    while(n>0){
        d=n%10;
        sum=sum+pow(d,size);
        n=n/10;
    }
    cout<<(temp==sum)<<" ";
}

int main(){
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        armstrong(n);
    }
}