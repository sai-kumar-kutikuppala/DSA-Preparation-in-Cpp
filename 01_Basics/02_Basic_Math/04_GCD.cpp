/*
Find GCD of two numbers

Problem Statement: Given two integers N1 and N2, find their greatest common divisor.

Example 1:
Input: N1 = 9, N2 = 12

Output: 3
Explanation:
Factors of 9: 1, 3, 9
Factors of 12: 1, 2, 3, 4, 6, 12
Common Factors: 1, 3
Greatest common factor: 3 (GCD)

Example 2:
Input: N1 = 20, N2 = 15

Output: 5
Explanation:
Factors of 20: 1, 2, 4, 5, 10, 20
Factors of 15: 1, 3, 5, 15
Common Factors: 1, 5
Greatest common factor: 5 (GCD)
*/

#include<iostream>
using namespace std;

void GCD(int n1,int n2){
    int gcd=1;
    for(int i=1;i<=min(n1,n2);i++){
        if(n1%i==0 && n2%i==0){
            gcd=i;
        }
    }
    cout<<gcd<<" ";
}

void euclidean(int n1,int n2){
    while(n1>0 && n2>0){
        if(n1>n2)
            n1 = n1%n2;
        else
            n2 = n2%n1;
    }
    if(n1==0)
        cout<<n2<<" ";
    else
        cout<<n1<<" ";
}

int main(){
    int T,n1,n2;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n1>>n2;
        GCD(n1,n2);
    }
    cout<<endl;

    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n1>>n2;
        euclidean(n1,n2);
    }
}

/*
input.txt:
3
9 12
11 13
20 40
3
9 12
11 13
20 40
*/