/*
Check if a number is Palindrome or Not

Problem Statement: Given an integer N, return true if it is a palindrome else return false.
A palindrome is a number that reads the same backward as forward. For example, 121, 1331, and 4554 are palindromes because they remain the same when their digits are reversed.

Example 1:
Input:N = 4554
Output:Palindrome Number
Explanation: The reverse of 4554 is 4554 and therefore it is palindrome number
                                        
Example 2:
Input:N = 7789          
Output: Not Palindrome
Explanation: The reverse of number 7789 is 9877 and therefore it is not palindrome
*/

#include<iostream>
using namespace std;

void reverse(int n){
    int d,num=0,temp=n;
    while(n>0){
        d=n%10;
        n=n/10;
        num=num*10+d;
    }
    cout<<(num==temp)<<" ";
}

int main(){
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        reverse(n);
    }
}