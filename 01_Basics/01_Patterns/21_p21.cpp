#include<iostream>
using namespace std;

void p20(int n){
    for(int i=1;i<=n;i++){
        if(i==1||i==n){
            for(int j=1;j<=n;j++){
                cout<<"*";
            }
        cout<<endl;
        }
        else{
            cout<<"*";
            for(int j=1;j<=n-2;j++){
                cout<<" ";
            }
            cout<<"*";
        cout<<endl;
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    p20(n);
}