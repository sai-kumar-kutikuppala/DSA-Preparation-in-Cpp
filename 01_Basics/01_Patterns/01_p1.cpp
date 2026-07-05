#include<iostream>
using namespace std;

void p1(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    p1(n);
}