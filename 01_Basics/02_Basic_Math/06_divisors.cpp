/*
Print all Divisors of a given Number

Problem Statement: Given an integer N, return all divisors of N.
A divisor of an integer N is a positive integer that divides N without leaving a remainder. In other words, if N is divisible by another integer without any remainder, then that integer is considered a divisor of N

Input: N = 36
Output: [1, 2, 3, 4, 6, 9, 12, 18, 36]  
Explanation: The divisors of 36 are 1, 2, 3, 4, 6, 9, 12, 18, 36.
Input: N = 12
Output: [1, 2, 3, 4, 6, 12]
Explanation: The divisors of 12 are 1, 2, 3, 4, 6, 12.
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

void print_divisors(int n){
    vector<int> v;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            v.push_back(i);
            if(n/i != i)
                v.push_back(n/i);
        }
    }

    sort(v.begin(),v.end());
    
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}

int main(){
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        print_divisors(n);
    }
}