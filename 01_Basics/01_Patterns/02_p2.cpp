#include<iostream>
using namespace std;

void p2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
    cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    p2(n);
}