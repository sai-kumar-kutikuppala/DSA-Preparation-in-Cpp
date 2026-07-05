/*
prob1: To find the element at the coordinates (R,C) where R is the row number and C is the Column number

prob2: To print the Nth row of the pascal triangle

prob3: To generate the entire Pascal’s Triangle for the first N rows

*/
#include<iostream>
using namespace std;

int findNCR(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

int prob1(int r,int c){
    return findNCR(r-1,c-1);
}

void prob2_brute(int n){
    for(int c=1;c<=n;c++){
        cout<<(findNCR(n-1,c-1))<<" ";
    }
}

void prob2_optimal(int n){
    long long res=1;
    cout<<1<<" ";
    for(int i=1;i<n;i++){
        res=res*(n-i);
        res=res/i;
        cout<<res<<" ";
    }
}

void prob3_brute(int n){ // uses prob2_brute approach
    for(int r=1;r<=n;r++){
        for(int c=1;c<=r;c++){
             cout<<(findNCR(r-1,c-1))<<" ";
        }
        cout<<endl;
    }
}

void prob3_optimal(int n){ // uses prob2_optimal approach
    for(int r=1;r<=n;r++){
        cout<<1<<" ";
        long long res=1;
        for(int c=1;c<r;c++){
            res=res*(r-c);
            res=res/c;
            cout<<res<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int r,c;
    cin>>r>>c;
    cout<<prob1(r,c)<<endl<<endl;

    int n0;
    cin>>n0;
    prob2_brute(n0);
    cout<<endl;

    prob2_optimal(n0);
    cout<<endl<<endl;

    int n;
    cin>>n;
    prob3_brute(n);
    cout<<endl<<endl;

    prob3_optimal(n);
    cout<<endl;
}