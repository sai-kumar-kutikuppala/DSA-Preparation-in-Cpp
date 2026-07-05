/*
Set the rightmost bit

Problem Statement: Given a positive integer n, set the rightmost unset (0) bit of its binary representation to 1 and return the resulting integer.
If all bits are already set, return the number as it is.

Examples
Example 1:
Input:
 n = 10 (binary: 1010)  
Output:
 11 (binary: 1011)  
Explanation:
  The rightmost unset bit is the least significant bit (LSB). Setting it to 1 gives 1011 = 11.

Example 2:
Input:
 n = 7 (binary: 111)  
Output:
 7 (binary: 111)  
Explanation:
  All bits are already set to 1, so the number remains the same.
*/

#include<iostream>
#include<algorithm>
using namespace std;

string conevrt2Binary(int n){
    string bin;
    while(n!=0){
        if(n%2==1)
            bin+="1";
        else
            bin+="0";
        n=n/2;
    }
    reverse(bin.begin(),bin.end());
    return bin;
}

int convert2Decimal(string bin){
    int n = bin.size();
    int num=0,p2=1;
    for(int i=n-1;i>=0;i--){
        if(bin[i]=='1')
            num+=p2;
        p2=p2*2;
    }
    return num;
}

int brute(int n){
    string bin = conevrt2Binary(n);
    int len = bin.size();
    for(int i=len-1;i>=0;i--){
        if(bin[i]=='0'){
            bin[i]='1';
            break;
        }
    }
    return convert2Decimal(bin);
}

int optimal(int n){
    return n | (n+1);
}

int main(){
    int n;
    cin>>n;

    cout<<brute(n)<<endl;
    cout<<optimal(n)<<endl;
}