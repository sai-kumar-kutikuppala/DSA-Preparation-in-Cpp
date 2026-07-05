#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n){
    if(n<0)
        return;
        
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    bubble_sort(arr,n-1);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bubble_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}