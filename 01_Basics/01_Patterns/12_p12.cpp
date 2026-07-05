#include<iostream>
using namespace std;

void p12(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        for(int j=1;j<=n*2-2*i;j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
    cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    p12(n);
}