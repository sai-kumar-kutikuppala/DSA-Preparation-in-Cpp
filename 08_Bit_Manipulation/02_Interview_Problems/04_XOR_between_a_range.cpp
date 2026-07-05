/*
Find XOR of numbers from L to R

Problem Statement: Given two integers L and R. Find the XOR of the elements in the range [L , R].

Examples
Example 1:
Input :
 L = 3 , R = 5
Output :
 2
Explanation : 
answer = (3 ^ 4 ^ 5) = 2.

Example 2:
Input :
 L = 1, R = 3
Output :
 0
Explanation : 
answer = (1 ^ 2 ^ 3) = 0.
*/

#include<iostream>
using namespace std;

int brute(int L,int R){
    int XOR=0;
    for(int i=L;i<=R;i++){
        XOR = XOR^i;
    }
    return XOR;
}

int func(int n){
    if(n % 4==1) return 1;
    else if(n % 4==2) return n+1;
    else if(n % 4==3) return 0;
    else return n;
}

int optimal(int L,int R){
    return func(L-1)^func(R);
}

int main(){
    int L,R;
    cin>>L>>R;

    cout<<brute(L,R)<<endl;
    cout<<optimal(L,R)<<endl;
}