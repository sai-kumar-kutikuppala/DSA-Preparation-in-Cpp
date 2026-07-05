#include<iostream>
using namespace std;

void p11(int n){
    for(int i=1;i<=n;i++){
        int start;
        if(i%2==0)
            start=0;
        else
            start=1;
        for(int j=1;j<=i;j++){
            cout<<start<<" ";
            start=(start+1)%2;
        }
    cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    p11(n);
}