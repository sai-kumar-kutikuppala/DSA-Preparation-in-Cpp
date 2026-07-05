#include<iostream>
using namespace std;

void p10(int n){
   for(int i=1;i<=n*2-1;i++){
        if(i<=n){
            for(int j=1;j<=i;j++){
                cout<<"*";
            }
        cout<<endl;
        }
        else{
            for(int j=1;j<=n*2-i;j++){
                cout<<"*";
            }
        cout<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;
    p10(n);
}