/*
Count digits in a number
Problem Statement: Given an integer N, return the number of digits in N.

Example 1:
Input:N = 12345
Output:5
Explanation:  The number 12345 has 5 digits.
                        
Example 2:
Input:N = 7789              
Output: 4
Explanation: The number 7789 has 4 digits. 
*/

#include<iostream>
using namespace std;

void count_digits(int n){
    int cnt=0;
    while(n>0){
        n=n/10;
        cnt++;
    }
    cout<<cnt<<" ";
}

int main(){
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        count_digits(n);
    }
}