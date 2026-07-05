#include<iostream>
using namespace std;

void p20(int n){
    int space=2;
    for(int i=1;i<=2*n-1;i++){
        if(i<=n){
            for(int j=1;j<=i;j++){
                cout<<"*";
            }
            for(int j=1;j<=(n-i+1)*2-2;j++){
                cout<<" ";
            }
                for(int j=1;j<=i;j++){
                cout<<"*";
            }
        }

        else{
            for(int j=1;j<=n*2-i;j++){
                cout<<"*";
            }
            for(int j=1;j<=space;j++){
                cout<<" ";
            }
            space+=2;
            for(int j=1;j<=n*2-i;j++){
                cout<<"*";
            }
        }
    cout<<endl;
    }
    
}

int main(){
    int n;
    cin>>n;
    p20(n);
}