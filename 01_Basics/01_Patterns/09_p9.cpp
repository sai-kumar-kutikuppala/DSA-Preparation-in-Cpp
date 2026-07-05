#include<iostream>
using namespace std;

void p9(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i*2-1;j++){
            cout<<"*";
        }
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
    cout<<endl;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            cout<<" ";
        }
        for(int j=1;j<=(n-i+1)*2-1;j++){
            cout<<"*";
        }
        for(int j=1;j<=1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    p9(n);
}