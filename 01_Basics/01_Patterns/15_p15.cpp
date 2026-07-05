#include<iostream>
using namespace std;

void p15(int n){
    for(int i=1;i<=n;i++){
        char ch='A';
        for(int j=1;j<=n-i+1;j++){
            cout<<ch<<" ";
            ch++;
        }
    cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    p15(n);
}